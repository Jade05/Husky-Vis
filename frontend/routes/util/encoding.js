var const_variable = require('./const');
var util = require('./util');
var channel = require('./channel/init');
var common = require('../common/common');

// collect attributes
function collectAttributes(schema) {
	var attributes = [];

	for (var i = 0; i < schema.length; i++) {
		var elem = schema[i];
		attributes.push(elem['field_name']);
	}

	return attributes;
}

// collect data types
function collectDataTypes(schema) {
	var dataTypes = {};

	for (var i = 0; i < schema.length; i++) {
		var elem = schema[i];
		var field = elem['field_name'];
		var type = elem['data_type'];

		dataTypes[field] = type;
	}

	return dataTypes;
}

/**
 * [calculateScores description]
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
 * [{
 * 	"score": 1,    // 整个按照score进行排序
 * 	"set": {
 * 	 	"measure": "name",
 *    	"dimension": "year",
 *     	"chartType": "Q_Q_POINT",
 *      "aggregateType": "SUM",
 *      "statisticalMethod": "variance",
 *      "groupByRawData": {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]},
 *      "aggregateData": {"1992": 6, "1993": 6, "1994": 6}
 *   }
 * },
 * {
 *  "score": 2,
 *  "set": {
 *  	"measure": "name",
 *    	"dimension": "year",
 *     	"chartType": "Q_Q_POINT",
 *      "aggregateType": "SUM",
 *      "statisticalMethod": "variance",
 *      "groupByRawData": {"1992": [1, 2, 3], "1993": [1, 2, 3], "1994": [1, 2, 3]},
 *      "aggregateData": {"1992": 6, "1993": 6, "1994": 6}
 *  }
 * }]
 */
function calculateScores(sets, topk) {
	var result = [];
	var min = -1;

	for (var i = 0; i < sets.length; i++) {
		var set = sets[i];
		var item = {
			'score': 0,
			'set': null
		};
		// calculate chartType score
		var chartTypeScore = const_variable.CHART_TYPE_CHANNEL_SCORE[set['chartType']];
		// calculate statisticalMethod score
		var statisticalData = common.getValuesFromObj(set['aggregateData']);

		var statisticalMethodScore = util.variance(statisticalData);

		item.score = chartTypeScore + statisticalMethodScore;
		item.set = set;

		// make sure result has topK score sets
		if (i < topk && item.score !== Infinity) {
			result.push(item);
			// update min value
			min = item.score < min ? item.score : min;
		} else {
			if (item.score > min && item.score !== Infinity) {
				// pop the item whose score is min, then push the new item
				// find the minist item pos
				var pos = 0;
				for (var j = 0; j < result.length; j++) {
					if (result[j].score === min) {
						pos = j;
						break;
					}
				}
				// remove
				result.splice(pos, 1);
				// add item with higher score
				result.push(item);
				// update min value
				min = result[0].score;
				for (var k = 1; k < result.length; k++) {
					min = result[k].score < min ? result[k].score : min;
				}
			}
		}
	}

	return result;
}

var encoding = {};

/**
 * [encoding description]
 * @param  {[type]} schema       [{"key": "OPERATOR", "field_name": "Aircraft__Airline_Operator","enabled": true}]
 * @param  {[type]} data         [description]
 * @param  {[type]} selectedElem [description]
 * @return {[type]}              [description]
 */
encoding.encoding = function (schema, data, selectedElem) {
	console.log('start encoding...');

	// go through generatedChannel
	var fields = collectAttributes(schema);
	var generatedSet = channel.generatedChannel.generatedChannel(fields, selectedElem);
	console.log('go through generatedChannel... ' + generatedSet.length);

	// go through chartTypeChannel
	var types = collectDataTypes(schema);
	var chartTypeSet = channel.chartTypeChannel.chartTypeChannel(generatedSet, types);
	console.log('go through chartTypeChannel... ' + chartTypeSet.length);

	// go through aggregateTypeChannel
	var aggregateTypeSet = channel.aggregateTypeChannel.aggregateTypeChannel(chartTypeSet);
	console.log('go through aggregateTypeChannel... ' + aggregateTypeSet.length);

	// go through statisticalMethodChannel
	var statisticalMethodSet = channel.statisticalMethodChannel.statisticalMethodChannel(aggregateTypeSet);
	console.log('go through statisticalMethodChannel... ' + statisticalMethodSet.length);

	// go through dataChannel
	var dataProcessRawSet = channel.processDataChannel.processRawDataChannel(statisticalMethodSet, data);
	console.log('go through processRawDataChannel... ' + dataProcessRawSet.length);

	var dataProcessAggregateSet = channel.processDataChannel.processAggregateDataChannel(dataProcessRawSet);
	console.log('go through processAggregateDataChannel... ' + dataProcessAggregateSet.length);

	// calcute scores
	var topkSet = calculateScores(dataProcessAggregateSet, 10);

	// encoding to chart

	return topkSet;
};

module.exports = encoding;
