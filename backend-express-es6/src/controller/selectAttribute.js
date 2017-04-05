import promise from 'bluebird';

export function selectAttribute(req, res, next) {
	res.send({"data": [1, 2, 4]});
}