var client = require('./gen-nodejs/client');

var connect = {};

connect.init = function() {
    client.init();
};

connect.end = function() {
    client.end();
};

connect.get_suggestions = function (callback) {
    client.api.get_suggestions(callback);
};

connect.get_attributes = function (callback) {
    client.api.get_attributes(callback);
};

module.exports = connect;