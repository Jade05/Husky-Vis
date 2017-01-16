var bar = require('./bar');
var line = require('./line');
var point = require('./point');

var chartMap = {
  'bar': bar.barFormat,
  'line': line.lineFormat,
  'point': point.pointFormat
};

module.exports = chartMap;
