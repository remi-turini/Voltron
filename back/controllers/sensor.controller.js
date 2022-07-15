const sensor = require("../models/sensor.js");

async function getAllValues(req, res) {

    const sensors = await sensor.find()
    res.json({"result": sensors});
}

async function registerSensorValue(req, res) {

}

module.exports = {
    getAllValues: getAllValues
}