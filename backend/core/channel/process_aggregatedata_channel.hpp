#pragma once
#include <iostream>
#include <vector>

#include "../common/base_obj.hpp"

namespace husky {
namespace visualization {

class ProcessAggregateDataChannel {
public:
    ProcessAggregateDataChannel() = default;
    ~ProcessAggregateDataChannel() = default;
    void process_aggregatedata_suggestions(std::vector<husky::visualization::BaseObj> dataset);
    std::vector<husky::visualization::BaseObj> get_aggregatedata_suggestions();
private:
    std::vector<husky::visualization::BaseObj> suggestions;
};

}
}