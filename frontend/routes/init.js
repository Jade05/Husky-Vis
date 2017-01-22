var index = require("./index");

exports.init = function(app) {
    app.use('/', index);
};
