var thrift = require('thrift');  
         
var service = require('./Something.js')  
ttypes = require('./my_types');  
         
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
  
client.ping(function (err, response) {
    console.log('ping()');
    connection.end();
});  
  
