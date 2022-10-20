const mongoose = require("mongoose");

const schema = new mongoose.Schema({
    type: 'string',
    value: 'number',
}, {
    collection: "sensor"
});

const sensor = mongoose.model('Sensor', schema);

module.exports = sensor;