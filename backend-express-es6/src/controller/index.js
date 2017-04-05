import promise from 'bluebird';

import {connect} from './connect/connect';
import {handlerAttributes, handlerSuggestions} from './handler/handler'

export function index(req, res, next) {
  let result = {
    "title": "Husky-Visualization",
    "data": {
      "attributes": [],
      "selectedVis": [],
      "recommendedVis": []
    }
  };

  // promisify all
  promise.promisifyAll(connect);
  // connect to c++ backend
  connect.init();

  connect.get_attributesAsync().then(function(response) {
      // get the attributes
      result.data.attributes = handlerAttributes(response);

      connect.get_suggestionsAsync().then(function(response) {
        // get topksuggestions visualization result
        result.data.recommendedVis = handlerSuggestions(response);

        // response frontend
        res.send(JSON.parse(JSON.stringify(result)));
        connect.end();
      }).catch(function(err) {
        console.log(err);
      });

  }).catch(function(err) {
    console.log(err);
  });
};
