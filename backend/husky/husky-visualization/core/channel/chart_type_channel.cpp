#include <iostream>
#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/optional/optional.hpp>
#include <boost/foreach.hpp>

#include "chart_type_channel.hpp"
#include "../common/base_obj.hpp"
#include "../common/constant.hpp"

namespace husky {
namespace visualization {

  using boost::property_tree::ptree;
  using boost::property_tree::ptree_error;

  /**
   * [ChartTypeChannel::chart_type_suggesstions description]
   * @param dataset [description]  [{"measure": "name", "dimension": "year"},{"measure": "name", "dimension": "cylinder"}]
   * @param schema [description]  {"name": "N", "year": "Q"}
   * @param constant [description]
   *
   * default: the first attribute as a measure, the second as a dimension, it may constomizable later
   */
  void ChartTypeChannel::chart_type_suggesstions(std::vector<husky::visualization::BaseObj> dataset,
    std::map<std::string, std::string> schema,
    husky::visualization::Constant constant) {
      ptree data_type_map_chart_type = constant.get_data_type_map_chart_type_method();
      ptree two_dimension_chart = data_type_map_chart_type.get_child("TWO_DIMENSION_CHART");

      for(auto dataset : set) {
        const string measure = set.measure;
        const string dimension = set.dimension;

        const string measure_value_type = schema.find(measure);
        const string dimension_value_type = schema.find(dimension);

        // identify measure
        boost::optional<ptree&> measure_opt = two_dimension_chart.get_child_optional(measure_value_type);
        if (measure_opt) {
          boost::optional<ptree&> dimension_opt = measure_opt.get_child_optional(dimension_value_type);
            // add chart type to set
            BOOST_FOREACH(ptree::value_type & v, boost::optional<ptree&> dimension_opt) {
              set.chart_type = v.second.data();
              suggestions.push_back(set);
            }
        }
      }
  }

  /**
   * [{"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT"}
   * ,{"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR"}]
   */
  std::vector<husky::visualization::BaseObj> ChartTypeChannel::get_chart_type_suggestions() {
    return suggestions;
  }

}
}
