#pragma once
#include <iostream>
#include <vector>

#include "../common/base_obj.hpp"
#include <boost/property_tree/ptree.hpp>

namespace husky {
namespace visualization {

using boost::property_tree::tree;

class ProcessRawDataChannel {
public:
    ProcessRawDataChannel() = default;
    ~ProcessRawDataChannel() = default;
    void process_rawdata_suggestions(std::vector<husky::visualization::BaseObj> dataset, ptree data);
    std::vector<husky::visualization::BaseObj> get_rawdata_suggestions();
private:
    std::vector<husky::visualization::BaseObj> suggestions;
};

}
}