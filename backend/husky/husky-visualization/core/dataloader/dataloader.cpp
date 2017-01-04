#include <fstream>
#include <iostream>
#include <boost/format.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "../../../core/context.hpp"

#include "dataloader.hpp"

namespace husky {
namespace visualization {

using boost::property_tree::ptree;
using boost::property_tree::ptree_error;

// may need template
void DataLoader::load_data() {
    std::string data_path = husky::Context::get_param("data");

    // default data is in ./mockup/...
    try {
        read_json(data_path, data);
    } catch (ptree_error & e) {
    }

}

ptree DataLoader::get_data() {
    return data;
}

void DataLoader::load_shema() {
    std::string data_schema_path = husky::Context::get_param("data_schema");

    try {
        read_json(data_schema_path, data_schema);
    } catch (ptree_error & e) {

    }
}

ptree DataLoader::get_data_schema() {
    return data_schema;
}

}
}