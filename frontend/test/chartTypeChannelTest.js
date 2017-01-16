var chartTypeChannel = require('../routes/util/channel/chartTypeChannel');
var chartTypeChannelTestData = [
  {"dimension": "year", "measure": "name"},
  {"dimension": "name", "measure": "year"},
  {"dimension": "cylinder", "measure": "name"},
  {"dimension": "name", "measure": "cylinder"}
];
var chartTypeChannelTestDataSchema = {"name": "N", "year": "T", "cylinder": "Q"}

console.log(chartTypeChannel.chartTypeChannel(chartTypeChannelTestData, chartTypeChannelTestDataSchema));
