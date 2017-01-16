var processDataChannel = require('../routes/util/channel/processDataChannel');
var processRawDataChannelTestSet = [
  {"measure": "cylinder", "dimension": "year", "chartType": "Q_T_POINT", "aggregateType": "SUM", "statisticalMethod": "variance"},
  {"measure": "cylinder", "dimension": "name", "chartType": "Q_N_BAR", "aggregateType": "COUNT", "statisticalMethod": "variance"}
];
var processRawDataChannelTestData = [
  {"name": "mingming1", "year": 1992, "cylinder": 1},
  {"name": "mingming1", "year": 1992, "cylinder": 1},
  {"name": "mingming3", "year": 1992, "cylinder": 2},
  {"name": "mingming4", "year": 1992, "cylinder": 2},
  {"name": "mingming5", "year": 1995, "cylinder": 3},
  {"name": "mingming5", "year": 1995, "cylinder": 4},
  {"name": "mingming7", "year": 1995, "cylinder": 4},
  {"name": "mingming7", "year": 1995, "cylinder": 5},
  {"name": "mingming10", "year": 1995, "cylinder": 6},
  {"name": "mingming10", "year": 1995, "cylinder": 7}
];
var processAggregateDataChannelTestData = [
  { measure: 'cylinder',
    dimension: 'year',
    chartType: 'Q_T_POINT',
    aggregateType: 'SUM',
    statisticalMethod: 'variance',
    groupByRawData: { '1992': [1, 1, 2, 2], '1995': [3, 4, 4, 5, 6, 7] }
  },
  { measure: 'cylinder',
    dimension: 'name',
    chartType: 'Q_N_BAR',
    aggregateType: 'COUNT',
    statisticalMethod: 'variance',
    groupByRawData: {
      mingming1: [1, 1],
      mingming3: [2],
      mingming4: [2],
      mingming5: [3, 4],
      mingming7: [4, 5],
      mingming10: [6, 7]
     }
   }
];

console.log(processDataChannel.processRawDataChannel(processRawDataChannelTestSet, processRawDataChannelTestData));
console.log(processDataChannel.processAggregateDataChannel(processAggregateDataChannelTestData));
