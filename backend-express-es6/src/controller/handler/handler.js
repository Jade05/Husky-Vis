import {encoding} from '../encoding/encoding';

export function handlerAttributes(attributes) {
  let result = [];

  for (let i = 0; i < attributes.length; i++) {
    result.push(attributes[i].name);
  }

  return result;
};

export function handlerSuggestions(suggestions) {
  let result = [];

  for (let i = 0; i < suggestions.length; i++) {
    let chartType = (suggestions[i].chart_type + '').substr(4);
    let encodingValue = encoding(suggestions[i], chartType);
    result.push(encodingValue);
  }

  return result;;
};
