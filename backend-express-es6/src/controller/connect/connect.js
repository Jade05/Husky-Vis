import {client} from './gen-nodejs/client';

let connect = {};

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

connect.select_attribute = function(attribute, callback) {
	client.api.select_attribute(attribute, callback);
}

export {connect};
