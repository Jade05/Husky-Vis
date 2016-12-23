#include <fstream>
#include <iostream>
#include <boost/format.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "constant.hpp"

namespace husky {
namespace visualization {

using boost::property_tree::ptree;
using boost::property_tree::ptree_error;

void Constant::init_constant(const std::string& constant_file) {
    ptree root;
    try {
        read_json(constant_file, root);
    } catch (ptree_error & e) {
    }

    // set values
    chart_type = root.get_child("CHART_TYPE");
    aggregate = root.get_child("AGGREGATE");
    statistical_method = root.get_child("STATISTIC");
    data_type_map_chart_type = root.get_child("DATA_TYPE_MAP_CHART_TYPE");
    chart_type_channel_score = root.get_child("CHART_TYPE_CHANNEL_SCORE");
}

ptree Constant::get_chart_type() {
    return chart_type;
}

ptree Constant::get_aggregate() {
    return aggregate;
}

ptree Constant::get_statistic() {
    return statistical_method;
}

ptree Constant::get_data_type_map_chart_type_method() {
    return data_type_map_chart_type;
}

ptree Constant::get_chart_type_channel_score() {
    return chart_type_channel_score;
}

}
}


