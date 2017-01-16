var common = require('../../common/common');

var generatedChannel = {};

/**
 * [generatedSuggestedset description]
 * @param  {[type]} dataset           ["name", "year", "cylinder"]
 * @param  {[type]} selectedAttribute [description]
 * @return {[type]}                   [description]
 */
generatedChannel.generatedChannel = function (dataset, selectedAttribute) {
	/**
	 * result [{"measure": "name", "dimension": "year"},{"measure": "name", "dimension": "cylinder"}]
	 *
	 * @type {Array}
	 */
	var result = [];
	// if the user selected an attribute, generate suggested set based on this attribute
	if (selectedAttribute) {
		// overide
	} else {
		for (var i = 0; i < dataset.length; i++) {
			for (var j = i + 1; j < dataset.length; j++) {
				var pair = {
					'measure': '',
					'dimension': ''
				};
				pair['measure'] = dataset[i];
				pair['dimension'] = dataset[j];
				result.push(pair);

				// reverse
				var reversePair = {
					'measure': '',
					'dimension': ''
				};
				reversePair['measure'] = dataset[j];
				reversePair['dimension'] = dataset[i];
				result.push(reversePair);
			}
		}
	}

	return result;
};


module.exports = generatedChannel;
