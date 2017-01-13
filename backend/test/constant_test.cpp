#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <string>
#include "core/common/constant.hpp"

using namespace std;
using namespace boost::property_tree;

int main() {
    husky::visualization::Constant constant_test;
    constant_test.init_constant("/data/yuying/project/Husky-Vis/backend/core/common/constant.json");

    ptree chart_type = constant_test.get_chart_type();
    ptree aggregate = constant_test.get_aggregate();
    ptree statistical_method = constant_test.get_statistic();
    ptree data_type_map_chart_type = constant_test.get_data_type_map_chart_type_method();
    ptree chart_type_channel_score = constant_test.get_chart_type_channel_score();
    
    stringstream ss1;
    write_json(ss1, chart_type, false);
    string out1 = ss1.str();
    cout << out1;

    stringstream ss2;
    write_json(ss2, aggregate, false);
    string out2 = ss2.str();
    cout << out2;

    stringstream ss3;
    write_json(ss3, statistical_method, false);
    string out3 = ss3.str();
    cout << out3;

    stringstream ss4;
    write_json(ss4, data_type_map_chart_type, false);
    string out4 = ss4.str();
    cout << out4;

    stringstream ss5;
    write_json(ss5, chart_type_channel_score, false);
    string out5 = ss5.str();
    cout << out5;
    
}

