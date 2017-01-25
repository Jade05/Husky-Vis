#pragma once

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

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

namespace husky {
namespace visualization {

class Controller {
public:
    static void init_with_args(int argc, char** argv, std::vector<std::string> args) {
      husky::init_with_args(argc, argv, args);
    }

    static void init_visualization(std::vector<husky::visualization::SuggestionObject>& topk_suggestions, const std::string& select_attribute = "") {
      // distributed suggestions
      const std::string& distributed = husky::Context::get_param("distribute");
      husky::visualization::Constant constant;
      constant.init_constant(husky::Context::get_param("constant"));

      std::vector<husky::visualization::SuggestionObject> suggestions;
      go_nodata_channels(suggestions, select_attribute);

      std::vector<husky::visualization::SuggestionObject> all_calculated_suggestions;

      if (distributed == "suggestions") {
         husky::visualization::DataLoader dataloader;

         dataloader.load_data();
         ptree data = dataloader.get_data();

         // default strategy: suggestions loaded balance in each worker and each thread
         // in this situation, each machine each thread accesses the whole data
         // load balance according to thread
         int total_workers = husky::Context::get_num_workers();
         int items_per_worker = suggestions.size() / total_workers;

         // check if global_tid start with 0 or 1, assume start with 0
         int global_tid = husky::Context::get_global_tid();

         int start = items_per_worker * global_tid;
         // make sure all items will be processed
         int end = global_tid == total_workers - 1 ? suggestions.size() : start + items_per_worker;

         // each thread gets its own item part
         std::vector<husky::visualization::SuggestionObject> items_part(end - start);
         std::copy(suggestions.begin() + start, suggestions.begin() + end, items_part.begin());
         // go through process rawdata channel
         husky::visualization::ProcessRawDataChannel process_rawdata_channel;
         process_rawdata_channel.process_rawdata_suggestions(items_part, data);
         std::vector<husky::visualization::SuggestionObject> process_r_suggestions = process_rawdata_channel.get_rawdata_suggestions();

         // go through process aggregatedata channel
         // process aggregratedata channel
         husky::visualization::ProcessAggregateDataChannel process_aggregatedata_channel;
         process_aggregatedata_channel.process_aggregatedata_suggestions(process_r_suggestions);
         std::vector<husky::visualization::SuggestionObject> process_a_suggestions = process_aggregatedata_channel.get_aggregatedata_suggestions();

         // calculate scores
         for (int i = 0; i < process_a_suggestions.size(); i++) {
           husky::visualization::SuggestionObject suggestion_with_score = husky::visualization::Preprocess::calculate_scores(process_a_suggestions[i], constant);

           all_calculated_suggestions.push_back(suggestion_with_score);
         }
     } else if (distributed == "data") {
       // override
     }

     // get topk suggestions
     if (husky::Context::get_global_tid() == 0) {
         int topk = std::stoi(husky::Context::get_param("topk"));
         topk_suggestions = husky::visualization::Preprocess::get_topk_suggestions(all_calculated_suggestions, topk);
         husky::LOG_I << "topk: " << topk_suggestions.size();

         // output to check
         for (std::vector<husky::visualization::SuggestionObject>::iterator item = topk_suggestions.begin();
                 item != topk_suggestions.end(); item++) {
             cout << *item;
         }
     }
    }

    static void get_attributes(std::vector<std::string>& attributes) {
      // load data
      husky::visualization::DataLoader dataloader;

      dataloader.load_schema();
      ptree data_schema = dataloader.get_data_schema();

      attributes = husky::visualization::Preprocess::collect_attributes(data_schema);
    }

    static void go_nodata_channels(std::vector<husky::visualization::SuggestionObject>& suggestions, const std::string& select_attribute) {
      // go through channels except process_rawdata_channel and process_aggregatedata_channel

      // load data
      husky::visualization::DataLoader dataloader;

      dataloader.load_schema();
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
      generate_channel.generate_suggestions(attributes, select_attribute);
      std::vector<husky::visualization::SuggestionObject> g_suggestions = generate_channel.get_generated_suggestions();

      // go through chart_type_channel
      husky::visualization::ChartTypeChannel chart_type_channel;
      chart_type_channel.chart_type_suggestions(g_suggestions, attribute_type, constant);
      std::vector<husky::visualization::SuggestionObject> c_suggestions = chart_type_channel.get_chart_type_suggestions();

      // go through aggregate channel
      husky::visualization::AggregateChannel aggregate_channel;
      aggregate_channel.aggregate_suggestions(c_suggestions, constant);
      std::vector<husky::visualization::SuggestionObject> a_suggestions = aggregate_channel.get_aggregate_suggestions();

      // go through statistic channel
      husky::visualization::StatisticChannel statistic_channel;
      statistic_channel.statistic_suggestions(a_suggestions, constant);
      std::vector<husky::visualization::SuggestionObject> s_suggestions = statistic_channel.get_statistic_suggestions();

      // set
      suggestions = s_suggestions;
    }
};

}
}
