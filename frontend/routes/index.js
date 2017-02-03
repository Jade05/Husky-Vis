var promise = require("bluebird");
var express = require('express');
var router = express.Router();

var connect = require('./connect/connect');
var handler = require('./handler/handler');

/* GET home page. */
router.get('/', function(req, res, next) {

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
        res.render('main', JSON.parse(JSON.stringify(result)));

        // connect.end();
      }).catch(function(err) {
        console.log(err);
      });

  }).catch(function(err) {
    console.log(err);
  });

});


module.exports = router;
