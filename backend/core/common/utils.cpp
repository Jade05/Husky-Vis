#include <map>
#include <vector>
#include "utils.hpp"


namespace husky {
namespace visualization {

std::map<std::string, std::function<double(std::vector<double>)>> Util::map_function = {
    {"SUM", Util::sum},
    {"MEAN", Util::mean},
    {"MAX", Util::max},
    {"MIN", Util::min},
    {"VARIANCE", Util::variance}
};

}
}
