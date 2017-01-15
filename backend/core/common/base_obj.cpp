#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "base_obj.hpp"

namespace husky {
namespace visualization {

int count = 0;

std::ostream& operator<<(std::ostream& stream, SuggestionObject& base_obj) {
    stream << "measure: " << base_obj.key.measure << std::endl
        << "dimension: " << base_obj.key.dimension << std::endl
        << "chart_type: "<< base_obj.key.chart_type << std::endl
        << "aggregate_type: " << base_obj.key.aggregate_type << std::endl
        << "statistical_method: " << base_obj.key.statistical_method << std::endl;

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

    size_t hash<husky::visualization::SuggestionObject>::operator()(const husky::visualization::SuggestionObject& obj) const {
        return hash<std::string>()(obj.key.measure)^hash<std::string>()(obj.key.dimension)
            ^hash<std::string>()(obj.key.chart_type)^hash<std::string>()(obj.key.aggregate_type)
            ^hash<std::string>()(obj.key.statistical_method);
    }

}
