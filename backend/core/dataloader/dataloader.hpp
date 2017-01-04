#pragma once

#include <boost/property_tree/ptree.hpp>

namespace husky {
namespace visualization {

using boost::property_tree::ptree;

class DataLoader {
public:
    Constant() = default;
    ~Constant() = default;

    void load_data();
    ptree get_data();

    void load_schema();
    ptree get_data_schema();

private:
    ptree data;
    ptree data_schema;
};

}
}