#pragma once

#include <boost/property_tree/ptree.hpp>

namespace husky {
namespace visualization {
    using boost::property_tree::ptree;

    class Constant {
    public: 
	Constant() = default;
	~Constant() = default;

	// init constant params from constant.json
	void init_constant(const std::string& constant_file);

	// get each part constant
	ptree get_chart_type();
	ptree get_aggregate();
	ptree get_statistical_method();
        ptree get_data_type_map_chart_type_method();
        ptree get_chart_type_channel_score();
            
    private:
        // currently support chart types
        ptree chart_type;
        // currently support aggregate functions
        ptree aggregate;
        // currently support statistical methods
        ptree statistical_method;
        // currently define the relation between data type and chart type
        ptree data_type_map_chart_type;
        // currently define chart type score
        ptree chart_type_channel_score;
    };

}
}
