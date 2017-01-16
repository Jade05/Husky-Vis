var const_variable = require('../const');
var util = require('../util');

var STATISTICAL_METHOD = const_variable.STATISTICAL_METHOD;

var statisticalMethodChannel = {};

/**
 * [statisticalMethodChannel description]
 * @param  {[type]} dataset [description]
 * [{"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT", "aggregateType": "SUM"}
 * ,{"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR", "aggregateType": "COUNT"}]
 *
 * @return {[type]}         [description]
 * [{"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT", "aggregateType": "SUM", "statisticalMethod": "variance"}
 * ,{"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR", "aggregateType": "COUNT", "statisticalMethod": "variance"}]
 */
statisticalMethodChannel.statisticalMethodChannel = function (dataset) {
	var result = [];

	for (var i = 0; i < dataset.length; i++) {
		for (var j = 0; j < STATISTICAL_METHOD.length; j++) {
			var pair = dataset[i];
			pair['statisticalMethod'] = STATISTICAL_METHOD[j];

			result.push(pair);
		}
	}

	return result;
};

/**
 * [variance description] [measure1， measure2, measure3...]
 * @param  {[type]} data [description]
 * @return {[type]}      [description]
 */
statisticalMethodChannel.variance = function (data) {
	return util.variance(data);
};

module.exports = statisticalMethodChannel;
