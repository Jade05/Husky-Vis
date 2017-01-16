var dataSchema = require('../mock/schema/birdstrikes-schema.json');
var dataDetail = require('../mock/data/birdstrikes.json');

var encoding = require('../routes/util/encoding');

var result = {
  "title": "demo",
  "data": {
    "attributes": [],
    "selectedVis": [],
    "recommendatedVis": []
  }
};

// handle attributes
function handleAttributes() {
  var attributes = [];

  for (var i = 0; i < dataSchema.length; i++) {
    attributes.push(dataSchema[i].field_name);
  }

  return attributes;
}

// handle selectedVis
function handleSelectedVis() {
  var selectedVis = [];

  var vlSpec = {
    "data": {
      "values": [
        {"a": "C", "b": 2}, {"a": "C", "b": 7}, {"a": "C", "b": 4},
        {"a": "D", "b": 1}, {"a": "D", "b": 2}, {"a": "D", "b": 6},
        {"a": "E", "b": 8}, {"a": "E", "b": 4}, {"a": "E", "b": 7}
      ]
    },
    "mark": "bar",
    "encoding": {
      "y": {"field": "a", "type": "nominal"},
      "x": {
        "aggregate": "average", "field": "b", "type": "quantitative",
        "axis": {
          "title": "Average of b"
        }
      }
    }
  };

  selectedVis.push(vlSpec);

  return selectedVis;
}

// handle recommendatedVis
function handleRecommendatedVis() {
  var recommendatedVis = [];

  var vlSpec = {
    "data": {
      "values": [
        {"a": "C", "b": 2}, {"a": "C", "b": 7}, {"a": "C", "b": 4},
        {"a": "D", "b": 1}, {"a": "D", "b": 2}, {"a": "D", "b": 6},
        {"a": "E", "b": 8}, {"a": "E", "b": 4}, {"a": "E", "b": 7}
      ]
    },
    "mark": "bar",
    "encoding": {
      "y": {"field": "a", "type": "nominal"},
      "x": {
        "aggregate": "average", "field": "b", "type": "quantitative",
        "axis": {
          "title": "Average of b"
        }
      }
    }
  };

  recommendatedVis.push(vlSpec);

  return recommendatedVis;
}

/* POST home page. */
var vis = {};

vis.init = function (req, res, next) {
  result.data.attributes = handleAttributes();
  result.data.selectedVis = handleSelectedVis();
  result.data.recommendatedVis = handleRecommendatedVis();

  var encodingResult = encoding.encoding(dataSchema, dataDetail, '');
  res.send(encodingResult);
};

module.exports = vis;
