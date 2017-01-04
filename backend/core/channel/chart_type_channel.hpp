#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "../common/base_obj.hpp"
#include "../common/constant.hpp"

namespace husky {
namespace visualization {

class ChartTypeChannel {
public:
    ChartTypeChannel() = default;
    ~ChartTypeChannel() = default;
    void chart_type_suggestions(std::vector<husky::visualization::BaseObj> dataset, std::map<std::string, std::string> schema, husky::visualization::Constant constant);
    std::vector<husky::visualization::BaseObj> get_chart_type_suggestions();
        
private:
    std::vector<husky::visualization::BaseObj> suggestions;
};

}
}
