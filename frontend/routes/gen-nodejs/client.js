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

/*
client.get_suggestions(function(err, response) {
    console.log(response);
    connection.end();
});
*/

client.get_attributes(function(err, response) {
    console.log(response);
    connection.end();
});
