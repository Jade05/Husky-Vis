var thrift = require('thrift');  
         
var service = require('./App.js')  
ttypes = require('./app_types');  
         
var transport = thrift.TBufferedTransport;
var protocol = thrift.TBinaryProtocol;

var connection = thrift.createConnection('proj99', 9090, {
    transport: transport,
    protocol: protocol
});  
  
connection.on("error", function(err) {
    console.error(err);  
});  
  
var client = thrift.createClient(service, connection);  
  
var test = [];
client.init_run(test);
/*
client.init_run(test, function (err, response) {
    console.log(response);
    console.log('ping()');
    connection.end();
});  
*/

