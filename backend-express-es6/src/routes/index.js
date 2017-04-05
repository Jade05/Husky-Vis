import {index} from '../controller/index'
import {selectAttribute} from '../controller/selectAttribute'

export function routes(app) {
	app.get('/', index);
	app.get('/selectAttribute', selectAttribute);
};
