#pragma once

#include <boost/property_tree/ptree.hpp>

namespace husky {
namespace vis {
	using namespace boost::property_tree;

	/**
	 * current support chart types
	 *
	 * ["BAR", "LINE", "POINT"]
	 */
	const ptree CHART_TYPE;
	CHART_TYPE.push_back("BAR");
	CHART_TYPE.push_back("LINE");
	CHART_TYPE.push_back("POINT");

	/**
	 * current support aggregate
	 *
	 * ["COUNT", "MEAN", "MAX", "MIN", "SUM"]
	 */
	const ptree AGGREGATE;
	AGGREGATE.push_back("COUNT");
	AGGREGATE.push_back("MEAN");
	AGGREGATE.push_back("MAX");
	AGGREGATE.push_back("MIN");
	AGGREGATE.push_back("SUM");

	/**
	 * current support statistical methods
	 *
	 * ["VARIANCE"]
	 */
	const ptree STATISTICAL_METHOD;
	STATISTICAL_METHOD.push_back(VARIANCE);

	/**
	 * current data_type_map_chart_type
	 *
	 * {
			"Q": {
				"Q": ["Q_Q_POINT"],
				"T": ["Q_T_LINE", "Q_T_BAR", "Q_T_POINT"],
				"O": ["Q_O_LINE", "Q_O_BAR", "Q_O_POINT"],
				"N": ["Q_N_BAR", "Q_N_POINT"]
			},
			"T": {
				"T": [],
				"O": [],
				"N": ["T_N_POINT"]
			},
			"O": {
				"O": [],
				"N": ["O_N_POINT"]
			},
			"N": {
				"N": []
			}
		};
	 */
	const ptree DATA_TYPE_MAP_CHART_TYPE;
	ptree arr, object;
	
	arr.push_back("Q_Q_POINT");
	object.add_child("Q", arr);
	DATA_TYPE_MAP_CHART_TYPE.add_child("Q", object);
	arr.clear();
	object.clear();

	arr.push_back("Q_T_LINE");
	arr.push_back("Q_T_BAR");
	arr.push_back("Q_T_POINT");
	object.add_child("T", arr);
	DATA_TYPE_MAP_CHART_TYPE.add_child("Q", object);
	arr.clear();
	object.clear();

	arr.push_back("Q_O_LINE");
	arr.push_back("Q_O_BAR");
	arr.push_back("Q_O_POINT");
	object.add_child("O", arr);
	DATA_TYPE_MAP_CHART_TYPE.add_child("Q", object);
	arr.clear();
	object.clear();

	arr.push_back("Q_N_BAR");
	arr.push_back("Q_N_POINT");
	object.add_child("N", arr);
	DATA_TYPE_MAP_CHART_TYPE.add_child("Q", object);
	arr.clear();
	object.clear();

	arr.push_back("");
	object.add_child("T", arr);
	DATA_TYPE_MAP_CHART_TYPE.add_child("T", object);
	arr.clear();
	object.clear();

	arr.push_back("");
	object.add_child("T", arr);
	DATA_TYPE_MAP_CHART_TYPE.add_child("T", object);
	arr.clear();
	object.clear();

	DATA_TYPE_MAP_CHART_TYPE.add_child("T");
	DATA_TYPE_MAP_CHART_TYPE.add_child("O");
	DATA_TYPE_MAP_CHART_TYPE.add_child("N");

	/**
	 * current chart_type score strategy 
	 *
	 * {
			"Q_Q_POINT": 3,
			"Q_T_LINE": 3,
			"Q_O_LINE": 3,
			"Q_N_BAR": 3,
			"T_N_POINT": 3,
			"O_N_POINT": 3,

			"Q_T_BAR": 2,
			"Q_O_BAR": 2,
			"Q_N_POINT": 2,

			"Q_T_POINT": 1,
			"Q_O_POINT": 1
		};
	 */
	const ptree CHART_TYPE_CHANNEL_SCORE;
}
}