#pragma once

#include <map>
#include <vector>

#include <boost/property_tree/ptree.hpp>

#include "core/common/base_obj.hpp"

namespace husky {
namespace visualization {

using boost::property_tree::ptree;

class Preprocess {
public:

    /**
     * collectAttributes
     */
    static std::vector<std::string> collectAttributes(ptree data_schema) {
      std::vector<const std::string> attributes;

      BOOST_FOREACH(ptree::value_type & v, data_schema) {
        const std::string& attribute = v.second.find("field_name")->second.data();
        attributes.push_back(attribute);
      }

      return attributes;
    }

    /**
     * collectSchemaType
     */
    static std::map<std::string, std::string> collectSchemaType(ptree data_schema) {
      std::map<std::string, std::string> attribute_type;

      BOOST_FOREACH(ptree::value_type & v, data_schema) {
        const std::string& attribute = v.second.find("field_name")->second.data();
        const std::string& data_type = v.second.find("data_type")->second.data();

        attribute_type.emplace(attribute, data_type);
      }

      return attribute_type;
    }

    /**
     * [get_topk_suggestions description]
     * @param  {[type]} set  [description]
     * [{"measure": "name",
     *   "dimension": "year",
     *   "chartType": "Q_Q_POINT",
     *   "aggregateType": "SUM",
     *   "statisticalMethod": "variance",
     *   "groupByRawData": {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]},
     *   "aggregateData": {"1992": 6, "1993": 6, "1994": 6}
     *   }
     * ,{"measure": "name",
     *   "dimension": "cylinder",
     *   "chartType": "Q_T_BAR",
     *   "aggregateType": "COUNT",
     *   "statisticalMethod": "variance",
     *   "groupByRawData": {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]}
     *   "aggregateData": {"1992": 3, "1993": 3, "1994": 3}
     * }]
     *
     * @param  {[type]} topk [description] 返回topk的结果, default 10
     * @return {[type]}      [description]
     *
     * [{"measure": "name",
     *   "dimension": "year",
     *   "chartType": "Q_Q_POINT",
     *   "aggregateType": "SUM",
     *   "statisticalMethod": "variance",
     *   "groupByRawData": {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]},
     *   "aggregateData": {"1992": 6, "1993": 6, "1994": 6}，
     *   “score”: 2
     *   }
     * ,{"measure": "name",
     *   "dimension": "cylinder",
     *   "chartType": "Q_T_BAR",
     *   "aggregateType": "COUNT",
     *   "statisticalMethod": "variance",
     *   "groupByRawData": {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]}
     *   "aggregateData": {"1992": 3, "1993": 3, "1994": 3},
     *   "score": 1
     * }]
     *
     */
     static vector<husky::visualization::BaseObj> get_topk_suggestions(std::vector<husky::visualization::BaseObj> & suggestions, int & topk) {
       std::vector<husky::visualization::BaseObj> result;
       // we think topk is always small and there is no need to keep all  suggestions. So we don't sort all suggestions
       if (suggestions.size() <= topk) {
         result = suggestions;
       } else {
         double min_score = -1;

         for (std::vector<husky::visualization::BaseObj>::iterator suggestion = suggestions.begin(), int i = 0;
          suggestion != suggestions.end(); suggestion++, i++) {
            if (i < topk) {
              result.push_back(*suggestion);
              // update min value
              min_score = *suggestion.score < min ? *suggestion.score : min_score;
            } else {
              if (*suggestion.score > min_score) {
                // pop the item whose score is min, then push the new item
                // find the minist item pos
                int pos = 0;
                for (int j = 0; j < result.size(); j++) {
                  if(result[j].score == min_score) {
                    pos = j;
                    break;
                  }
                }
                // erase
                result.erase(result.begin() + pos, result.begin() + pos + 1);
                // add item with higher score
                result.push_back(*suggestion);
                // update min_score
                min_score = *suggestion.score;
                // get the global min score in result
                for (int k = 0; k < result.length; k++) {
                  min_score = result[k].score < min_score ? result[k].score : min_score;
                }
              }
            }
         }
       }

       return result;
     }

};

}
}
