var encoding = require('../routes/util/encoding');
var dataSchema = require('../mock/schema/birdstrikes-schema.json');
var dataDetail = require('../mock/data/birdstrikes.json');

console.log(encoding.encoding(dataSchema, dataDetail));
