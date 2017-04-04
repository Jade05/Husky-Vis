var index = require("./index");
var selectAttribute = require("./selectAttribute");

exports.init = function(app) {
    app.get('/', index);
    app.get('/selectAttribute', selectAttribute.selectAttribute);
};
