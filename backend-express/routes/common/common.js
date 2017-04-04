var common = {};

common.deepCopyObj = function (srcObj) {
  var targetObj = {};

  if (typeof srcObj != 'object') {
    return srcObj;
  }

  for (var attr in srcObj) {
    targetObj[attr] = common.deepCopyObj(srcObj[attr]);
  }

  return targetObj;
};

/**
 * [sortObjByKey description] {"1992": 6, "1991": 6, "1994": 6}
 * @return {[type]} {"1994": 6, "1992": 6, "1991": 6}
 */
common.sortObjByKey = function (obj) {

};

/**
 * [getValuesFromObj {"1992": 6, "1991": 7, "1994": 8}
 * @type {[type]} [6, 7, 8]
 */
common.getValuesFromObj = function (obj) {
	var result = [];

	for (key in obj) {
		result.push(obj[key]);
	}

	return result;
};

module.exports = common;
