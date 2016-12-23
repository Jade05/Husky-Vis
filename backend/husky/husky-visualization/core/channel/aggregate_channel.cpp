#include <iostream>
#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/optional/optional.hpp>
#include <boost/foreach.hpp>

#include "aggregate_channel.hpp"
#include "../common/base_obj.hpp"
#include "../common/constant.hpp"

namespace husky {
namespace visualization {

    using boost::property_tree::ptree;
    using boost::property_tree::ptree_error;

    /**
     * [AggregateChannel::aggregate_channel description]
     * @param dataset  
     * [{"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT"}
     * ,{"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR"}]
     * 
     * @param constant [description]
     */
    void AggregateChannel::aggregate_suggestions(std::vector<husky::visualization::BaseObj> dataset, husky::visualization::Constant constant) {
        ptree aggregate = constant.get_aggregate();

        for (auto set : dataset) {
            BOOST_FOREACH(ptree::value_type & v, aggregate) {
                set.aggregate_type = v.second.data();
                suggestions.push_back(set);
            }
        }
    }

    /**
     * [{"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT", "aggregateType": "SUM"}
     * ,{"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR", "aggregateType": "COUNT"}]
     */
    std::vector<husky::visualization::BaseObj> AggregateChannel::get_aggregate_suggestions() {
        return suggestions;
    }
}
}
