var encoding = require('../encoding/encoding');

var handler = {};

handler.handlerAttributes = function (attributes) {
  var result = [];

  for (var i = 0; i < attributes.length; i++) {
    result.push(attributes[i].name);
  }

  return result;
};

handler.handlerSuggestions = function (suggestions) {
  var result = [];

  for (var i = 0; i < suggestions.length; i++) {
    var chartType = (suggestions[i].chart_type + '').substr(4);
    var encodingValue = encoding.encoding(suggestions[i], chartType);
    result.push(encodingValue);
  }

  return result;;
};

module.exports = handler;
