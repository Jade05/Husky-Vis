var promise = require("bluebird");
var connect = require('./connect/connect');
var encoding = require('./encoding/encoding');

/* POST home page. */
var selectAttribute = {};

selectAttribute.selectAttribute = function (req, res, next) {
  console.log(req.body.selectAttribute);
  res.send({"name": "helloworld"});
};

module.exports = selectAttribute;
