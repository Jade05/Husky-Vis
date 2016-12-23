#include <iostream>
#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>

#include "statistic_channel.hpp"
#include "../common/base_obj.hpp"
#include "../common/constant.hpp"

namespace husky {
namespace visualization {

    using boost::property_tree::ptree;
    using boost::property_tree::ptree_error;

    void StatisticChannel::statistic_suggestions(std::vector<husky::visualization::BaseObj> dataset, husky::visualization::Constant constant) {
        ptree statistic = constant.get_statistic();

        for(auto set : dataset) {
            BOOST_FOREACH(ptree::value_type & v, statistic) {
                set.statistical_method = v.second.data();
                suggestions.push_back(set);
            }
        }
    }

    std::vector<husky::visualization::BaseObj> StatisticChannel::get_statistic_suggestions() {
        return suggestions;
    }

}
}
