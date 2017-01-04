#include <iostream>
#include <vector>
#include <map>

#include "../core/channel/generate_channel.hpp"
#include "../core/channel/chart_type_channel.hpp"
#include "../core/channel/aggregate_channel.hpp"
#include "../core/common/base_obj.hpp"
#include "../core/common/constant.hpp"

using namespace std;

int main () {
    // constant
    husky::visualization::Constant constant_test;
    constant_test.init_constant("../core/common/constant.json");
    
    // generate_channel
    std::vector<std::string> generate_dataset;
    generate_dataset.push_back("name");
    generate_dataset.push_back("year");
    generate_dataset.push_back("cylinder");

    husky::visualization::GenerateChannel generate_channel_test;
    generate_channel_test.generate_suggestions(generate_dataset, "name");
    
    std::vector<husky::visualization::BaseObj> suggestions = generate_channel_test.get_generated_suggestions();

    std::map<std::string, std::string> schema;
    schema.emplace("name", "N");
    schema.emplace("year", "T");
    schema.emplace("cylinder", "Q");

    // chart_type_channel
    husky::visualization::ChartTypeChannel chart_type_channel_test;
    chart_type_channel_test.chart_type_suggestions(suggestions, schema, constant_test);
    std::vector<husky::visualization::BaseObj> chart_suggestions = chart_type_channel_test.get_chart_type_suggestions();

    // aggregate channel
    husky::visualization::AggregateChannel aggregate_channel_test;
    aggregate_channel_test.aggregate_suggestions(chart_suggestions, constant_test);
    std::vector<husky::visualization::BaseObj> aggregate_suggestions = aggregate_channel_test.get_aggregate_suggestions();

    // output
    for (std::vector<husky::visualization::BaseObj>::iterator item = aggregate_suggestions.begin(); item != aggregate_suggestions.end(); item++) {
        cout << *item;
    }

}
