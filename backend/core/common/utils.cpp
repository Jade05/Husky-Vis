#include <map>
#include <vector>
#include "utils.hpp"


namespace husky {
namespace visualization {

std::map<std::string, std::function<double(std::vector<double>)>> Utils::map_function = {
    {"SUM", Utils::sum},
    {"MEAN", Utils::mean},
    {"MAX", Utils::max},
    {"MIN", Utils::min},
    {"VARIANCE", Utils::variance}
};

}
}
