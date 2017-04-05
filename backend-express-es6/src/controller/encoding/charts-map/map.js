import {barFormat} from './charts/bar'
import {lineFormat} from './charts/line'
import {pointFormat} from './charts/point'
// var point = require('./charts/point');

let chartMap = {
  'bar': barFormat,
  'line': lineFormat,
  'point': pointFormat
};

export {chartMap};
