const express = require("express");
const router = express.Router();

const sensorController = require("../controllers/sensor.controller")

router.get("/", sensorController.getAllValues);
router.post("/", sensorController.registerValue);

module.exports = router;