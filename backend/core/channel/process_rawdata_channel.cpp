#include <iostream>
#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>

#include "process_rawdata_channel.hpp"
#include "../common/base_obj.hpp"

namespace husky {
namespace visualization {

    using boost::property_tree::ptree;
    using boost::property_tree::ptree_error;

    /**
     * [groupByDimension description]
     * @param  {[type]} datasets
     * [{"measure": "cylinder", "dimension": "year", "chartType": "Q_T_POINT", "aggregateType": "SUM", "statisticalMethod": "variance"}
     * ,{"measure": "cylinder", "dimension": "name", "chartType": "Q_N_BAR", "aggregateType": "COUNT", "statisticalMethod": "variance"}]
     *
     * @param  {[type]} data      [{},{}]
     * @return {[type]}           {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]}
     *
     * [{"measure": "name",
     *   "dimension": "year",
     *   "chartType": "Q_Q_POINT",
     *   "aggregateType": "SUM",
     *   "statisticalMethod": "variance",
     *   "groupByRawData": {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]}
     *   }
     * ,{"measure": "name",
     *   "dimension": "cylinder",
     *   "chartType": "Q_T_BAR",
     *   "aggregateType": "COUNT",
     *   "statisticalMethod": "variance",
     *   "groupByRawData": {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]}
     *   }]
     */
    void ProcessRawDataChannel::process_rawdata_suggestions(std::vector<husky::visualization::SuggestionObject> dataset, ptree data) {
        for (auto set : dataset) {
            std::string& dimension = set.key.dimension;
            std::string& measure = set.key.measure;

            BOOST_FOREACH(ptree::value_type & v, data) {
                std::string& dimensionValue = v.second.find(dimension)->second.data();
                double& measureValue = v.second.find(measure)->second.data();

                set.group_by_raw_data[dimensionValue].push_back(measureValue);
            }

            suggestions.push_back(set);
        }
    }

    std::vector<husky::visualization::SuggestionObject> ProcessRawDataChannel::get_rawdata_suggestions() {
        return suggestions;
    }
}
}
