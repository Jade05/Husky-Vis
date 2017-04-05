import promise from 'bluebird';

var connect = require('./connect/connect');
var handler = require('./handler/handler');

export function index(req, res, next) {
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
  	console.log(response);
      // get the attributes
      // result.data.attributes = handler.handlerAttributes(response);

      connect.get_suggestionsAsync().then(function(response) {
        // get topksuggestions visualization result
        // result.data.recommendedVis = handler.handlerSuggestions(response);
        
        // response frontend
        // res.render('main', JSON.parse(JSON.stringify(result)));
        // console.log('nihao----');
        // connect.end();
      }).catch(function(err) {
        console.log(err);
      });

  }).catch(function(err) {
    console.log(err);
  });
};