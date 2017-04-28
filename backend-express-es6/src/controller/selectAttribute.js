// import promise from 'bluebird';
import {connect} from './connect/connect';
import {handlerSuggestions} from './handler/handler'

export function selectAttribute(req, res, next) {
	let result = {
		"title": "Husky-Visualization",
		"data": {
	 		"attributes": [],
	  		"selectedVis": [],
	  		"recommendedVis": []
		}
	};

	let attribute = req.query.picked;

	async function getSelectAttributes() {
		let getSelectAttributePromise = await connect.select_attribute(attribute);
		return getSelectAttributePromise;
	}

	getSelectAttributes().then((data) => {
		result.data.selectedVis = handlerSuggestions(data);
		res.send(JSON.parse(JSON.stringify(result)));
	});

	// connect.select_attributeAsync(attribute).then(function(response) {
	// 	result.data.selectedVis = handlerSuggestions(response);
	// 	res.send(JSON.parse(JSON.stringify(result)));
	// }).catch(function(err) {
	// 	console.log(err);
    // });
}
