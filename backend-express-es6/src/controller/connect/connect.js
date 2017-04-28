import {client} from './gen-nodejs/client';

let connect = {};

connect.init = function() {
    client.init();
};

connect.end = function() {
    client.end();
};

connect.get_suggestions = function () {
    return new Promise((resolve, reject) => {
        client.api.get_suggestions((err, response) => {
            if(!err) resolve(response);
        });
    });
};

connect.get_attributes = function () {
    return new Promise((resolve, reject) => {
        client.api.get_attributes((err, response) => {
            if(!err) resolve(response);
        });
    });
};

connect.select_attribute = function(attribute) {
    return new Promise((resolve, reject) => {
        client.api.select_attribute(attribute, (err, response) => {
            if (!err) resolve(response);
        });
    });
}

export {connect};
