#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "../common/base_obj.hpp"
#include "../common/constant.hpp"

namespace husky {
namespace visualization {

class StatisticChannel {
public:
    StatisticChannel() = default;
    ~StatisticChannel() = default;
    void statistic_suggestions(std::vector<husky::visualization::BaseObj> dataset, husky::visualization::Constant constant);
    std::vector<husky::visualization::BaseObj> get_statistic_suggestions();
private:
    std::vector<husky::visualization::BaseObj> suggestions;
};

}
}
