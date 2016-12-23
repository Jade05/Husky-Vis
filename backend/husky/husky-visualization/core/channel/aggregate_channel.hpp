#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "../common/base_obj.hpp"
#include "../common/constant.hpp"

namespace husky {
namespace visualization {

class AggregateChannel {
public:
    AggregateChannel() = default;
    ~AggregateChannel() = default;
    void aggregate_suggestions(std::vector<husky::visualization::BaseObj> dataset, husky::visualization::Constant constant);
    std::vecotr<husky::visualization::BaseObj> get_aggregate_suggestions();
private:
    std::vecotr<husky::visualization::BaseObj> suggestions;
};

}
}
