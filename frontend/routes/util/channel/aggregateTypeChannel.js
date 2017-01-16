var common = require('../../common/common');

var const_variable = require('../const');
var util = require('../util');

var AGGREGATE = const_variable.AGGREGATE;

var aggregateTypeChannel = {};

/**
 * [aggregateTypeChannel
 * @param  {[type]} dataset [description]
 *
 * [{"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT"}
 * ,{"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR"}]
 *
 * @return {[type]}
 *
 * [{"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT", "aggregateType": "SUM"}
 * ,{"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR", "aggregateType": "COUNT"}]
 *
 * default: the first attribute as a measure, the second as a dimension, it may constomizable later. Aggregate for measure
 */
aggregateTypeChannel.aggregateTypeChannel = function (dataset) {
	var result = [];

	for (var i = 0; i < dataset.length; i++) {
		for (var j = 0; j < AGGREGATE.length; j++) {
			var pair = common.deepCopyObj(dataset[i]);
			var agg = AGGREGATE[j];

			// only quantity can be applied aggregate function
			if (pair['chartType'].startsWith('Q')) {
				pair['aggregateType'] = agg;
			} else {
				pair['aggregateType'] = '';
			}

			result.push(pair);
		}
	}

	return result;
};

/**
 * [count description]
 * @param {[type]} data [1, 2, 3, 4]
 */
aggregateTypeChannel.count = function (data) {
	return data.length;
};

/**
 * [SUM description]
 * @param {[type]} data [1, 2, 3, 4]
 */
aggregateTypeChannel.sum = function (data) {
	return util.sum(data);
};

/**
 * [MEAN description]
 * @param {[type]} data [1, 2, 3, 4]
 */
aggregateTypeChannel.mean = function (data) {
	return util.mean(data);
};

aggregateTypeChannel.max = function (data) {
	return util.max(data);
};

aggregateTypeChannel.min = function (data) {
	return util.min(data);
};

module.exports = aggregateTypeChannel;
