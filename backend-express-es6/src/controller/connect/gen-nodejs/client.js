var thrift = require('thrift');

var service = require('./App.js')
var ttypes = require('./app_types');

var transport = thrift.TBufferedTransport;
var protocol = thrift.TBinaryProtocol;

var client = {};

var connection;
client.init = function () {
    // connection = thrift.createConnection('137.189.90.147', 9090, {
    //     transport: transport,
    //     protocol: protocol
    // });

    connection = thrift.createConnection('137.189.90.42', 9090, {
        transport: transport,
        protocol: protocol
    });
    
    // connection = thrift.createConnection('proj99', 9090, {
    //     transport: transport,
    //     protocol: protocol
    // });

    connection.on("error", function(err) {
        console.error(err);
    });

    client.api = thrift.createClient(service, connection);
};

client.end = function () {
    connection.end();
};

module.exports = client;
