var point = {};

/**
 * [pointFormat description]
 * @param  {[type]} data [description]
 * {
 *   "x": {
 *    "name": "x",
 *    "values": [1, 2, 3, 4],
 *    "type": "ordinal"
 *   },
 *   "y": {
 *    "name": "y",
 *    "values": [1, 2, 3],
 *    "type": "quantitative",
 *    "aggregate": "avg"
 *   }
 * }
 *
 * @return {[type]}      [description]
 *
 * {
    "description": "A simple point chart with embedded data.",
    "data": {
      "values": [
        {"a": "A","b": 28},
        {"a": "B","b": 55},
        {"a": "C","b": 43},
        {"a": "D","b": 91},
        {"a": "E","b": 81},
        {"a": "F","b": 53},
        {"a": "G","b": 19},
        {"a": "H","b": 87},
        {"a": "I","b": 52}
      ]
    },
    "mark": "point",
    "encoding": {
      "x": {"field": "a","type": "ordinal"},
      "y": {"field": "b","type": "quantitative"}
    }
  }
 */
point.pointFormat = function (data) {
  var format = {
    "data": {
      "values": []
    },
    "mark": "point",
    "encoding": {
      "x": {"field": null, "type": null, "axis": {"title": null}},
      "y": {"field": null, "type": null, "axis": {"title": null}}
    }
  };

  var xName = data.x.name;
  var yName = data.y.name;
  var xType = data.x.type;
  var yType = data.y.type;
  var xData = data.x.values;
  var yData = data.y.values;
  var yAgg = data.y.aggregate;

  // process values
  for (var i = 0; i < xData.length && i < yData.length; i++) {
      var value = {};

      value[xName] = xData[i];
      value[yName] = yData[i];

      format.data.values.push(value);
  }

  format.encoding.x.field = xName;
  format.encoding.y.field = yName;

  format.encoding.x.type = xType;
  format.encoding.y.type = yType;

  format.encoding.x.axis.title = xName;
  format.encoding.y.axis.title = yAgg + ' of ' + yName;

  return format;
};

module.exports = point;
