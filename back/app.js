const express = require("express");
const app = express();
const bodyParser = require("body-parser");
const cors = require('cors');
const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost:27017/voltron').catch(error => console.log(error));

const sensorRoute = require("./routes/routes");

app.use(bodyParser.json(), cors());

app.use("/sensors", sensorRoute);

module.exports = app;