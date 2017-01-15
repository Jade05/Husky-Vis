#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "base_obj.hpp"

namespace husky {
namespace visualization {

int count = 0;

std::ostream& operator<<(std::ostream& stream, BaseObj& base_obj) {
    stream << "measure: " << base_obj.measure << std::endl
        << "dimension: " << base_obj.dimension << std::endl
        << "chart_type: "<< base_obj.chart_type << std::endl
        << "aggregate_type: " << base_obj.aggregate_type << std::endl
        << "statistical_method: " << base_obj.statistical_method << std::endl;

    stream << "group_by_raw_data: size_" << base_obj.group_by_raw_data.size() << std::endl;
    /*
    for (auto x : base_obj.group_by_raw_data) {
        stream << x.first;
        for (auto y : x.second) {
            stream << " " << y << std::endl;
        }
    }
    */

    stream << "aggregate_data: size_" << base_obj.aggregate_data.size() << std::endl;
    /*
    for(auto z : base_obj.aggregate_data) {
        stream << z.first << " " << z.second;
    }
    */

    stream << "score: " << base_obj.score << std::endl;

    stream << "-------------------------------------------------" << ++count << std::endl;
    return stream;
}
}
}

namespace std {

    size_t hash<husky::visualization::BaseObj>::operator()(const husky::visualization::BaseObj& obj) const {
        return hash<std::string>()(obj.measure)^hash<std::string>()(obj.dimension)
            ^hash<std::string>()(obj.chart_type)^hash<std::string>()(obj.aggregate_type)
            ^hash<std::string>()(obj.statistical_method);        
    }

}

