var thrift = require('thrift');  
         
var service = require('./App.js')  
var ttypes = require('./app_types');  
         
var transport = thrift.TBufferedTransport;
var protocol = thrift.TBinaryProtocol;

var client = {};

client.init = function () {
    var connection = thrift.createConnection('proj99', 9090, {
        transport: transport,
        protocol: protocol
    });

    connection.on("error", function(err) {
        console.error(err);  
    });

    client.api = thrift.createClient(service, connection);
};

client.end = function () {
    connection.end();
};

module.exports = client;
