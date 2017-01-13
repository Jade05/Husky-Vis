#include <iostream>
#include <string>
#include <vector>

#include "core/channel/generate_channel.hpp"
#include "core/common/base_obj.hpp"

using namespace std;
using namespace husky::visualization;

int main() {
    std::vector<std::string> dataset;
    
    dataset.push_back("name");
    dataset.push_back("year");
    dataset.push_back("cylinder");
    
    // test without selectedAttribute
    husky::visualization::GenerateChannel generate_channel_test;
    generate_channel_test.generate_suggestions(dataset, "name");
    std::vector<husky::visualization::BaseObj> suggestions = generate_channel_test.get_generated_suggestions();
    
    for (std::vector<husky::visualization::BaseObj>::iterator item = suggestions.begin(); item != suggestions.end(); item++) {
        cout << *item;
    }

    // test with selectedAttribute

}
