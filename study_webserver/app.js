const express = require('express');
const morgan = require('morgan');
const router = require('./routes');

const app = express();

// app관련 설정 및 미들웨어 설정

app.use(morgan('dev'));
app.use(router);


module.exports = app;