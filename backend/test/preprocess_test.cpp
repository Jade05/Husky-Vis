#include <iostream>
#include <vector>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "husky/core/engine.hpp"

#include "app/preprocess.hpp"
#include "core/dataloader/dataloader.hpp"

using namespace std;
using boost::property_tree::ptree;

int main (int argc, char** argv) {
    std::vector<std::string> args({
        "data",
        "data_schema",
        "distribute"
    });

    husky::init_with_args(argc, argv, args);

    husky::visualization::DataLoader dataloader;

    dataloader.load_data();
    dataloader.load_schema();

    ptree data = dataloader.get_data();
    ptree data_schema = dataloader.get_data_schema();

    std::vector<std::string> attributes = husky::visualization::Preprocess::collect_attributes(data_schema);
    cout << "attributes length: " << attributes.size() << endl;

    std::vector<std::string> attributes_type = husky::visualization::Preprocess::collect_schema_type(data_schema);
    count << "attribute length: " << attributes_type.size() << endl;
}
