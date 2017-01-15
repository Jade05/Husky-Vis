#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../common/base_obj.hpp"
#include "generate_channel.hpp"

namespace husky {
namespace visualization {

/**
 * dataset ["name", "year", "cylinder"]
 * selectedAttribute "name",
 * generate suggestions [{"measure": name, "dimension": year}, {"measure":name, "dimension": year}, ...]
 * */
void GenerateChannel::generate_suggestions(std::vector<std::string> dataset, const std::string& selectedAttribute) {
    husky::visualization::SuggestionObject suggestion;
    // no attribute selected
    if (selectedAttribute.length()) {
        for (std::vector<std::string>::iterator item = dataset.begin(); item != dataset.end(); item++) {
            suggestion.key.measure = selectedAttribute;
            suggestion.key.dimension = *item;

            suggestions.push_back(suggestion);

            // reset
            suggestion = {};

            if (*item != selectedAttribute) {
                // reserve
                suggestion.key.measure = *item;
                suggestion.key.dimension = selectedAttribute;

                suggestions.push_back(suggestion);

                 suggestion = {};
            }
        }
    } else {
        for (std::vector<std::string>::iterator item_a = dataset.begin(); item_a != dataset.end(); item_a++) {
            for (std::vector<std::string>::iterator item_b = dataset.begin(); item_b != dataset.end(); item_b++) {
                suggestion.key.measure = *item_a;
                suggestion.key.dimension = *item_b;

                suggestions.push_back(suggestion);

                // reset
                suggestion = {};

                if (*item_a != *item_b) {
                    // reverse
                    suggestion.key.measure = *item_b;
                    suggestion.key.dimension = *item_a;

                    suggestions.push_back(suggestion);

                    suggestion = {};
                }
            }
        }
    }
}

/**
 * return suggestions
 * [{"measure": "name", "dimension": "year"}, {...}]
 *
 **/
std::vector<husky::visualization::SuggestionObject> GenerateChannel::get_generated_suggestions() {
    return suggestions;
}

}
}
