const { Router } = require('express');

const router = Router();

router.get('/', (req, res) => {
    res.json(['user1', 'user2', 'user3']);
});

router.get('/hello', (req, res) => {
    res.send('hello');
});



module.exports = router;