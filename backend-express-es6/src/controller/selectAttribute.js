import promise from 'bluebird';
import {connect} from './connect/connect';
import {handlerAttributes, handlerSuggestions} from './handler/handler'

export function selectAttribute(req, res, next) {
	let result = {
		"title": "Husky-Visualization",
		"data": {
	 		"attributes": [],
	  		"selectedVis": [],
	  		"recommendedVis": []
		}
	};

	let attribute = req.body.selectAttribute;

	connect.select_attributeAsync(attribute).then(function(response) {
		result.data.selectedVis = handler.handlerSuggestions(response);
		res.send(JSON.parse(JSON.stringify(result)));
	}).catch(function(err) {
    	console.log(err);
  });
}
