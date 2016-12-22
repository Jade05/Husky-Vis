#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "../common/base_obj.hpp"

namespace husky {
namespace visualization {

class ChartTypeChannel {
public:
    ChartTypeChannel() = default;
    ~ChartTypeChannel() = default;
    void chart_type_suggesstions(std::vector<husky::visualization::BaseObj> dataset);
    std::vector<husky::visualization::BaseObj> get_chart_type_suggestions();
        
private:
    std::vector<husky::visualization::BaseObj> suggestions;
};

}
}
