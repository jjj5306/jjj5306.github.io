const { Router } = require('express');
const { readdirSync, statSync } = require('fs');
const { join } = require('path');
const router = Router();


readdirSync(__dirname) 
    .filter(dir => statSync(join(__dirname, dir)).isDirectory())
    .forEach(dir => router.use(`/&{dir}`, require(`./${dir}`)));

module.exports = router;