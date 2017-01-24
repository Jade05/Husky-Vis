var index = require("./index");
var selectAttribute = require("./selectAttribute");

exports.init = function(app) {
    app.use('/', index);
    app.post('/selectAttribute', selectAttribute.selectAttribute);
};
