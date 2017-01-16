var aggregateTypeChannel = require('../routes/util/channel/aggregateTypeChannel');
var aggregateTypeChannelTestData = [
  {"measure": "name1", "dimension": "year1", "chartType": "Q_Q_POINT"},
  {"measure": "name2", "dimension": "cylinder2", "chartType": "Q_T_BAR"}
];

console.log(aggregateTypeChannel.aggregateTypeChannel(aggregateTypeChannelTestData));
