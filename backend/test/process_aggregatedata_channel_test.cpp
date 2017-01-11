#include <iostream>
#include <vector>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "husky/core/engine.hpp"

#include "core/dataloader/dataloader.hpp"
#include "core/channel/generate_channel.hpp"
#include "core/channel/chart_type_channel.hpp"
#include "core/channel/aggregate_channel.hpp"
#include "core/channel/statistic_channel.hpp"
#include "core/channel/process_rawdata_channel.hpp"
#include "core/channel/process_aggregatedata_channel.hpp"
#include "core/common/base_obj.hpp"
#include "core/common/constant.hpp"

using namespace std;

int main () {
    std::vector<std::string> args({
        "data",
        "data_schema",
        "distribute"
    });

    husky::init_with_args(argc, argv, args);

    // constant
    husky::visualization::Constant constant_test;
    constant_test.init_constant("/data/yuying/project/Husky-Vis/backend/core/common/constant.json");

    // dataloader
    husky::visualization::DataLoader dataloader;
    dataloader.load_data();
    ptree data = dataloader.get_data();

    // generate_channel
    std::vector<std::string> generate_dataset;
    generate_dataset.push_back("Name");
    generate_dataset.push_back("Year");
    generate_dataset.push_back("Cylinders");

    husky::visualization::GenerateChannel generate_channel_test;
    generate_channel_test.generate_suggestions(generate_dataset, "Name");
    
    std::vector<husky::visualization::BaseObj> suggestions = generate_channel_test.get_generated_suggestions();

    std::map<std::string, std::string> schema;
    schema.emplace("Name", "N");
    schema.emplace("Year", "T");
    schema.emplace("Cylinders", "Q");

    // chart_type_channel
    husky::visualization::ChartTypeChannel chart_type_channel_test;
    chart_type_channel_test.chart_type_suggestions(suggestions, schema, constant_test);
    std::vector<husky::visualization::BaseObj> chart_suggestions = chart_type_channel_test.get_chart_type_suggestions();

    // aggregate channel
    husky::visualization::AggregateChannel aggregate_channel_test;
    aggregate_channel_test.aggregate_suggestions(chart_suggestions, constant_test);
    std::vector<husky::visualization::BaseObj> aggregate_suggestions = aggregate_channel_test.get_aggregate_suggestions();

    // statistic channel
    husky::visualization::StatisticChannel statistic_channel_test;
    statistic_channel_test.statistic_suggestions(aggregate_suggestions, constant_test);
    std::vector<husky::visualization::BaseObj> statistic_suggestions = statistic_channel_test.get_statistic_suggestions();

    // process rawdata channel
    husky::visualization::ProcessRawDataChannel process_rawdata_channel_test;
    process_rawdata_channel_test.process_rawdata_suggestions(statistic_suggestions, data);
    std::vector<husky::visualization::BaseObj> rawdata_suggestions = process_rawdata_channel_test.get_rawdata_suggestions();

    // process aggregratedata channel
    husky::visualization::ProcessAggregateDataChannel process_aggregatedata_channel_test;
    process_aggregatedata_channel_test.process_aggregatedata_suggestions(rawdata_suggestions);
    std::vector<husky::visualization::BaseObj> aggregatedata_suggestions = process_aggregatedata_channel_test.get_aggregate_suggestions();

    // output
    for (std::vector<husky::visualization::BaseObj>::iterator item = aggregatedata_suggestions.begin(); item != aggregatedata_suggestions.end(); item++) {
        cout << *item;
    }

}
