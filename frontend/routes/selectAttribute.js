var promise = require("bluebird");
var connect = require('./connect/connect');
var encoding = require('./encoding/encoding');

/* POST home page. */
var selectAttribute = {};

selectAttribute.selectAttribute = function (req, res, next) {
	var attribute = req.body.selectAttribute;
	console.log(req.body.selectAttribute);
	res.send({"name": "helloworld"});
	connect.select_attributeAsync().then(function(response, attribute) {
		console.log(response);
		console.log(attribute);
	}).catch(function(err) {
    console.log(err);
  });
};

module.exports = selectAttribute;
