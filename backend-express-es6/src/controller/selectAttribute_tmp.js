var promise = require("bluebird");
var connect = require('./connect/connect');
var handler = require('./handler/handler');

/* POST home page. */
var selectAttribute = {};

var result = {
	"title": "Husky-Visualization",
	"data": {
 		"attributes": [],
  		"selectedVis": [],
  		"recommendedVis": []
	}
};

selectAttribute.selectAttribute = function (req, res, next) {
	var attribute = req.body.selectAttribute;

	connect.select_attributeAsync(attribute).then(function(response) {
		result.data.selectedVis = handler.handlerSuggestions(response);
		res.render('chartFrame', result, function (err, html) {
			res.send({
				"html": html,
				"data": JSON.parse(JSON.stringify(result))
			});
		});
	}).catch(function(err) {
    	console.log(err);
  });
};

module.exports = selectAttribute;
