var bar = require('./charts/bar');
var line = require('./charts/line');
var point = require('./charts/point');

var chartMap = {
  'bar': bar.barFormat,
  'line': line.lineFormat,
  'point': point.pointFormat
};

module.exports = chartMap;
