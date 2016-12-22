#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "base_obj.hpp"

namespace husky {
namespace visualization {


std::ostream& operator<<(std::ostream& stream, BaseObj& base_obj) {
    stream << "measure: " << base_obj.measure << std::endl
        << "dimension: " << base_obj.dimension << std::endl
        << "chart_type: "<< base_obj.chart_type << std::endl
        << "aggregate_type: " << base_obj.aggregate_type << std::endl
        << "statistical_method: " << base_obj.statistical_method << std::endl;

    for (auto x : base_obj.group_by_raw_data) {
        stream << "group_by_raw_data: " << x.first;
        for (auto y : x.second) {
            stream << " " << y;
        }
    }

    for(auto z : base_obj.aggregate_data) {
        stream << std::endl<< "aggreagate_data: " << z.first << " " << z.second;
    }

    stream << "-------------------------------------------------" << std::endl;
    return stream;
}
}
}
