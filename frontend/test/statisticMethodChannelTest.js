var statisticalMethodChannel = require('../routes/util/channel/statisticalMethodChannel');

var statisticalMethodChannelTestData = [
  {"measure": "name", "dimension": "year", "chartType": "Q_Q_POINT", "aggregateType": "SUM"},
  {"measure": "name", "dimension": "cylinder", "chartType": "Q_T_BAR", "aggregateType": "COUNT"}
];

var varianceTestData = [1, 2, 3, 4, 5, 6];
console.log(statisticalMethodChannel.statisticalMethodChannel(statisticalMethodChannelTestData));
console.log(statisticalMethodChannel.variance(varianceTestData));
