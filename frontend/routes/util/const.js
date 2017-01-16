var CHART_TYPE = ["BAR", "LINE", "POINT"];

var AGGREGATE = ["COUNT", "MEAN", "MAX", "MIN", "SUM"];

var STATISTICAL_METHOD = ["VARIANCE"];

/**
 * quantitative => Q
 * temporal => T
 * ordinal => O
 * nominal => N
 * @type {[type]}   map table 
 *
 * [default] treated first param as a measure, second param as a dimension 
 */
var DATA_TYPE_MAP_CHART_TYPE = {
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

// temporary score strategy
var CHART_TYPE_CHANNEL_SCORE = {
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

var const_variable = {
	CHART_TYPE: CHART_TYPE,
	AGGREGATE: AGGREGATE,
	STATISTICAL_METHOD: STATISTICAL_METHOD,
	DATA_TYPE_MAP_CHART_TYPE: DATA_TYPE_MAP_CHART_TYPE,
	CHART_TYPE_CHANNEL_SCORE: CHART_TYPE_CHANNEL_SCORE
};

module.exports = const_variable;