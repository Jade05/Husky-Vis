// import promise from 'bluebird';

import {connect} from './connect/connect';
import {handlerAttributes, handlerSuggestions} from './handler/handler';

// let promisify = (fn, receiver) => {
//   return (...args) => {
//     return new Promise((resolve, reject) => {
//       fn.apply(receiver, [...args, (err, res) => {
//         return err ? reject(err) : resolve(res);
//       }]);
//     });
//   };
// };

export function index(req, res, next) {
  let result = {
    "title": "Husky-Visualization",
    "data": {
      "attributes": [],
      "selectedVis": [],
      "recommendedVis": []
    }
  };
  
  // connect to c++ backend
  connect.init();

  async function getAttributes() {
    let getAttributePromise = await connect.get_attributes();
    return getAttributePromise;
  }

  async function getSuggestions() {
    let getSuggestionsPromise = await connect.get_suggestions();
    return getSuggestionsPromise;
  }

  let attributesPromise = new Promise((resolve, reject) => {
    getAttributes().then((data) => {
      // set attributes
      result.data.attributes = handlerAttributes(data);
      resolve();
    });
  });

  let suggestionsPromise = new Promise((resolve, reject) => {
    getSuggestions().then((data) => {
      // set suggestions
      result.data.recommendedVis = handlerSuggestions(data);
      resolve();
    });
  });

  Promise.all([attributesPromise, suggestionsPromise]).then(() => {
    res.send(JSON.parse(JSON.stringify(result)));
  });


  /*
   * bluebird promisify implementation
   *
   */
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
