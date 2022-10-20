const sensorModel = require("../models/sensor.js");
const mongoose = require("mongoose");

async function getAllValues(req, res) {

    const sensors = await sensorModel.find()

    return res.json({
        state: "ok",
        message: null,
        data: sensors
    });
}

async function registerValue(req, res) {

    var type = req.query.type ?? null
    var value = req.query.value ?? null

    const date = new Date();
    const filter = { type: type };
    const update = { value: value };

    const sensor = await sensorModel.findOneAndUpdate(filter, update, {
        new: true
    });

    if (sensor === null)
    {
        return res.json({
            state: "error",
            message: "Aucun capteur trouvée",
            data: null
        });
    }

    return res.json({
        state: "ok",
        message: "Valeur du capteur enregistré avec succès",
        data: sensor
    });
}

module.exports = {
    getAllValues: getAllValues,
    registerValue: registerValue
}