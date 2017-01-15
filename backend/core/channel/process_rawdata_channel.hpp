#pragma once
#include <iostream>
#include <vector>

#include "../common/base_obj.hpp"
#include <boost/property_tree/ptree.hpp>

namespace husky {
namespace visualization {

using boost::property_tree::ptree;

class ProcessRawDataChannel {
public:
    ProcessRawDataChannel() = default;
    ~ProcessRawDataChannel() = default;
    void process_rawdata_suggestions(std::vector<husky::visualization::SuggestionObject> dataset, ptree data);
    std::vector<husky::visualization::SuggestionObject> get_rawdata_suggestions();
private:
    std::vector<husky::visualization::SuggestionObject> suggestions;
};

}
}
