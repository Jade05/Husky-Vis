var chartsMap = require('./charts-map/map');

var encoding = {};

/**
 * @param  {[type]} data [description]
 * {
        measure: 'Horsepower',
        dimension: 'Year',
        chart_type: 'Q_T_BAR',
        aggregate_type: 'SUM',
        statistical_method: 'VARIANCE',
        aggregate_data:
         { '1970-01-01': 5210,
           '1971-01-01': 3033,
           '1972-01-01': 3365,
           '1973-01-01': 5219,
           '1974-01-01': 2545,
           '1975-01-01': 3032,
           '1976-01-01': 3438,
           '1977-01-01': 2942,
           '1978-01-01': 3589,
           '1979-01-01': 2935,
           '1980-01-01': 2247,
           '1982-01-01': 4989 },
         score: 970939.222222222
    },
 * 
 * @return {[type]}      [description]
 */
encoding.encoding = function (data, chartType) {
    // pre encoding
    var chartEncoding = {
        "x": {
            "name:": "",
            "values": [],
            "type": "ordinal"
        },
        "y": {
            "name": "",
            "values": [],
            "type": "quantitative",
            "aggregate": ""
        }
    };

    chartEncoding.x.name = data.dimension;
    chartEncoding.y.name = data.measure;

    for(var obj in data.aggregate_data) {
        chartEncoding.x.values.push(obj);
        chartEncoding.y.values.push(data.aggregate_data[obj]);
    }

    chartEncoding.y.aggregate = data.aggregate_type.toLowerCase();

    // encoding
    encodingResult = chartsMap[('' + chartType).toLowerCase()](chartEncoding);

    return encodingResult;
}

module.exports = encoding;