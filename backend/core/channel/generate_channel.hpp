#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "../common/base_obj.hpp"

namespace husky {
namespace visualization {

class GenerateChannel {
public:
    GenerateChannel() = default;
    ~GenerateChannel() = default;
    // generate suggestion based on selectedAttributes
    // if selectedAttribuite is none, it means generating by default
    void generate_suggestions(std::vector<std::string> dataset,const std::string& selectedAttribute);
    std::vector<husky::visualization::BaseObj> get_generated_suggestions();
private:
    std::vector<husky::visualization::BaseObj> suggestions;
};

} // namespace visualization
} // namespace husky
