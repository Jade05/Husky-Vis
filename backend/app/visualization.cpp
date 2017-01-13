#include <iostream>

#include <string>
#include <vector>

#include "boost/property_tree/ptree.hpp"
#include "husky/core/engine.hpp"

#include "preprocess.hpp"
#include "core/common/base_obj.hpp"
#include "core/common/constant.hpp"
#include "core/dataloader/dataloader.hpp"

#include "core/channel/generate_channel.hpp"
#include "core/channel/chart_type_channel.hpp"
#include "core/channel/aggregate_channel.hpp"
#include "core/channel/statistic_channel.hpp"
#include "core/channel/process_rawdata_channel.hpp"
#include "core/channel/process_aggregatedata_channel.hpp"

using namespace std;
using boost::property_tree::ptree;

class SuggestionObject {
   public:
    typedef husky::visualization::BaseObj KeyT;
    KeyT key;

    explicit SuggestionObject(KeyT key) { this->key = key; }

    const KeyT& id() const { return key; }
};

void visualization() {
  // distributed suggestions
  const std::string& distributed = husky::Context::get_param("distribute");

  // go through channels except process_rawdata_channel and process_aggregatedata_channel
  
  // load data
  husky::visualization::DataLoader dataloader;

  dataloader.load_data();
  dataloader.load_schema();

  ptree data = dataloader.get_data();
  ptree data_schema = dataloader.get_data_schema();

  // load constant values
  husky::visualization::Constant constant;
  constant.init_constant(husky::Context::get_param("constant"));

  // preprocess data
  // collect attributes 
  std::vector<std::string> attributes = husky::visualization::Preprocess::collect_attributes(data_schema);
  // collect attributes_datatypes
  std::map<std::string, std::string> attribute_type = husky::visualization::Preprocess::collect_schema_type(data_schema);

  // go through generate_channel
  husky::visualization::GenerateChannel generate_channel;
  generate_channel.generate_suggestions(attributes, "");
  std::vector<husky::visualization::BaseObj> g_suggestions = generate_channel.get_generated_suggestions();

  // go through chart_type_channel
  husky::visualization::ChartTypeChannel chart_type_channel;
  chart_type_channel.chart_type_suggestions(g_suggestions, attribute_type, constant);
  std::vector<husky::visualization::BaseObj> c_suggestions = chart_type_channel.get_chart_type_suggestions();

  // go through aggregate channel
  husky::visualization::AggregateChannel aggregate_channel;
  aggregate_channel.aggregate_suggestions(c_suggestions, constant);
  std::vector<husky::visualization::BaseObj> a_suggestions = aggregate_channel.get_aggregate_suggestions();

  // go through statistic channel
  husky::visualization::StatisticChannel statistic_channel;
  statistic_channel.statistic_suggestions(a_suggestions, constant);
  std::vector<husky::visualization::BaseObj> s_suggestions = statistic_channel.get_statistic_suggestions();

  auto& suggestion_list = husky::ObjListStore::create_objlist<SuggestionObject>();
  auto& suggestion_ch = husky::ChannelStore::create_push_channel<husky::visualization::BaseObj>(suggestion_list, suggestion_list);

  // push into channel
  for (int i = 0; i < s_suggestions.size(); i++) {
    husky::visualization::BaseObj& suggestion = s_suggestions[i];
    suggestion_ch.push(suggestion, 0);
  }
  suggestion_ch.flush();

  std::vector<husky::visualization::BaseObj> all_calculated_suggestions;
  std::vector<husky::visualization::BaseObj> topk_suggestions;

  if (distributed == "suggestions") {
    // default strategy: suggestions loaded balance in each worker and each thread
    // in this situation, each machine each thread accesses the whole data
    husky::list_execute(suggestion_list, [&](SuggestionObject& obj) {
      auto& items = suggestion_ch.get(obj);

      // load balance according to thread
      int total_workers = husky::Context::get_num_workers();
      int items_per_worker = items.size() / total_workers;

      // check if global_tid start with 0 or 1, assume start with 0
      int global_tid = husky::Context::get_global_tid();

      int start = items_per_worker * global_tid;
      // make sure all items will be processed
      int end = global_tid == total_workers - 1 ? items.size() : start + items_per_worker;

      // each thread gets its own item part
      auto items_part = std::copy(start, end, items.begin());
      // go through process rawdata channel
      husky::visualization::ProcessRawDataChannel process_rawdata_channel;
      process_rawdata_channel.process_rawdata_suggestions(items_part, data);
      std::vector<husky::visualization::BaseObj> process_r_suggestions = process_rawdata_channel.get_rawdata_suggestions();
      
      // go through process aggregatedata channel
      // process aggregratedata channel
      husky::visualization::ProcessAggregateDataChannel process_aggregatedata_channel;
      process_aggregatedata_channel.process_aggregatedata_suggestions(process_r_suggestions);
      std::vector<husky::visualization::BaseObj> process_a_suggestions = process_aggregatedata_channel.get_aggregatedata_suggestions();

      // calculate scores
      for (int i = 0; i < process_a_suggestions.size(); i++) {
        husky::visualization::BaseObj suggestion_with_score = husky::visualization::Preprocess::calculate_scores(process_a_suggestions[i], constant);

        all_calculated_suggestions.push_back(suggestion_with_score);
      }
    });
  } else if (distributed == "data") {
    // override
  }

  // get topk suggestions
  if (husky::Context::get_global_tid() == 0) {
      int topk = 10;
      topk_suggestions = husky::visualization::Preprocess::get_topk_suggestions(all_calculated_suggestions, topk);
      husky::LOG_I << "topk: " << topk_suggestions.size();
  }
}

int main(int argc, char** argv) {
    std::vector<std::string> args({
        "data",
        "data_schema",
        "distribute",
        "topk",
        "constant"
    });

    if (husky::init_with_args(argc, argv, args)) {
        husky::run_job(visualization);
        return 0;
    }
    return 1;
}
