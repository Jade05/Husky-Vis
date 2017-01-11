#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace husky {
namespace visualization {

struct BaseObj {
    std::string measure;
    std::string dimension;
    std::string chart_type;
    std::string aggregate_type;
    std::string statistical_method;
    std::map<std::string, std::vector<double>> group_by_raw_data;
    std::map<std::string, double> aggregate_data;

};

std::ostream& operator<<(std::ostream& stream, BaseObj& base_obj);

}
}
