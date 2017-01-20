var connect = require('./connect/connect');

/* POST home page. */
var vis = {};

vis.init = function (req, res, next) {

    // promisify all
    promise.promisifyAll(connect);
    // connect to c++ backend
    connect.init();

    connect.get_suggestionsAsync().then(function(response) {
        console.log(response);
        res.send({});
        connect.end();
      }).catch(function(err) {
        console.log(err);
      });

};

module.exports = vis;
