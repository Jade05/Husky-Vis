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


  throw new Error('test');
  
  // connect to c++ backend
  connect.init();

  async function getAttributesAsync() {
    try {
      await connect.get_attributes();
    } catch (err) {
      console.log(err);
    }
  }

  async function getSuggestionsAsync() {
    try {
      await connect.get_suggestions();
    } catch (err) {
      console.log(err);
    }
  }

  getAttributesAsync.then(function(response) {
    console.log('attributes async');
    // get the attributes
    result.data.attributes = handlerAttributes(response);
  });

  getSuggestionsAsync.then(function(response) {
    console.log('suggestions async');
    // get suggestions
    result.data.recommendedVis = handlerSuggestions(response);

    // response frontend
    res.send(JSON.parse(JSON.stringify(result)));
  });

  // // promisify all
  // promise.promisifyAll(connect);
  // // connect to c++ backend
  // connect.init();
  //
  // connect.get_attributesAsync().then(function(response) {
  //     // get the attributes
  //     result.data.attributes = handlerAttributes(response);
  //
  //     connect.get_suggestionsAsync().then(function(response) {
  //       // get topksuggestions visualization result
  //       result.data.recommendedVis = handlerSuggestions(response);
  //
  //       // response frontend
  //       res.send(JSON.parse(JSON.stringify(result)));
  //     }).catch(function(err) {
  //       console.log(err);
  //     });
  //
  // }).catch(function(err) {
  //   console.log(err);
  // });
};
