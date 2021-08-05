const { Router } = require('express');

const userRouter = require('./user');

const router = Router();

router.use('/user', userRouter);

module.exports = router;