var fs = require('fs');
var promise = require("bluebird");
var connect = require('./connect');
var handler = require('../handler/handler');

  var result = {
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
      result.data.attributes = handler.handlerAttributes(response);

      connect.get_suggestionsAsync().then(function(response) {
        // get topksuggestions visualization result
        result.data.recommendedVis = handler.handlerSuggestions(response);
        
        // response frontend
        // console.log((JSON.stringify(result)));
        fs.writeFile('suggestions_raw.json', JSON.stringify(response), function(err) {
            if(err) console.log("dump unsuccessfully!");
            else console.log("dump successfully!");
        }); 

        // connect.end();
      }).catch(function(err) {
        console.log(err);
      });

  }).catch(function(err) {
    console.log(err);
  });

