var index = require("./index");
var vis = require("./vis");

exports.init = function(app) {
    app.use('/', index);
    app.post('/vis', vis.init);
};
