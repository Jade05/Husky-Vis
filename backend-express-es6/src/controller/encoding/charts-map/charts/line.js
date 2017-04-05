/**
 * [lineFormat description]
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
    "description": "A simple bar chart with embedded data.",
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
    "mark": "line",
    "encoding": {
      "x": {"field": "a","type": "ordinal"},
      "y": {"field": "b","type": "quantitative"}
    }
  }
 */
export function lineFormat(data) {
  let format = {
    "data": {
      "values": []
    },
    "mark": "line",
    "encoding": {
      "x": {"field": null, "type": null, "axis": {"title": null}},
      "y": {"field": null, "type": null, "axis": {"title": null}},
      "color": {"value": "#5cb85c"}
    }
  };

  let [xName, yName, xType, yType, xData, yData, yAgg] = [
    data.x.name, data.y.name, data.x.type, data.y.type, data.x.values, data.y.values, data.y.aggregate
  ];

  // process values
  for (let i = 0; i < xData.length && i < yData.length; i++) {
    let value = {};

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
