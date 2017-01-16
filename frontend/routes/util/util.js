/**
 * dataformat: [1, 2, 3, 4, 5] array
 */

var util = {};

/**
 * [SUM description]
 * @param {[type]} data [1, 2, 3, 4]
 */
util.sum = function (data) {
	var result = 0;

	for (var i = 0; i < data.length; i++) {
		result += data[i];
	}

	return result;
};

util.count = function (data) {
	return data.length;
};

util.mean = function (data) {
	return util.sum(data) / data.length;
};

util.max = function (data) {
	var max = data[0];

	for (var i = 1; i < data.length; i++) {
		if (data[i] > max) {
			max = data[i];
		}
	}

	return max;
};

util.min = function (data) {
	var min = data[0];

	for (var i = 0; i < data.length; i++) {
		if (data[i] < min) {
			min = data[i];
		}
	}

	return min;
};

util.variance = function (data) {
	var mean = util.mean(data);

	var sum = 0;
	for (var i = 0; i < data.length; i++) {
		sum += Math.pow(data[i] - mean, 2);
	}

	return sum / data.length;
};

module.exports = util;
