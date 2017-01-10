#include <iostream>
#include <vector>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "husky/core/engine.hpp"

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
    
    stringstream ss1;
    write_json(ss1, data, false);
    string out1 = ss1.str();
    cout << out1;

    stringstream ss2;
    write_json(ss2, data_schema, false);
    string out2 = ss2.str();
    cout << out2;
}
