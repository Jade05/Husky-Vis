var promise = require("bluebird");
var connect = require('./connect/connect');
var encoding = require('./encoding/encoding');

/* POST home page. */
var selectAttribute = {};

selectAttribute.selectAttribute = function (req, res, next) {
	var attribute = req.body.selectAttribute;

	connect.select_attributeAsync(attribute).then(function(response) {
		console.log("1234566");
		console.log(response);
		res.send({"name": "helloworld"});
	}).catch(function(err) {
		console.log("dhfjdhfjfdgh");
    	console.log(err);
  });
};

module.exports = selectAttribute;
