var common = require('../../common/common');
var const_variable = require('../const');

var DATA_TYPE_MAP_CHART_TYPE = const_variable.DATA_TYPE_MAP_CHART_TYPE;

var chartTypeChannel = {};

/**
 * [chartTypeChannel description]
 * @param  {[type]} dataset [description] [{"measure": "name", "dimension": "year"},{"measure": "name", "dimension": "cylinder"}]
 * @param  {[type]} schema  {"name": "N", "year": "Q"}
 *
 * @return {array}
 * [{"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT"}
 * ,{"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR"}]
 *
 * default: the first attribute as a measure, the second as a dimension, it may constomizable later
 */
chartTypeChannel.chartTypeChannel = function (dataset, schema) {
	var result = [];

	for (var i = 0; i < dataset.length; i++) {
		var pair = dataset[i];
		var elem0 = schema[pair['measure']];
		var elem1 = schema[pair['dimension']];

		// prunning, if the elem's schema doesn't map to DATA_TYPE_MAP_CHART_TYPE, it willn't be added into result
		if (DATA_TYPE_MAP_CHART_TYPE.hasOwnProperty(elem0)) {
			if (DATA_TYPE_MAP_CHART_TYPE[elem0].hasOwnProperty(elem1)) {
				var chartTypeArr = DATA_TYPE_MAP_CHART_TYPE[elem0][elem1];

				// enumerate
				for (var j = 0; j < chartTypeArr.length; j++) {
					var element = common.deepCopyObj(pair);
					element.chartType = chartTypeArr[j];
					result.push(element);
				}
			}
		}
	}

	return result;
};

module.exports = chartTypeChannel;
