const app = require('./app');
const http = require('http');
const {PORT} = require('./env');

const server = http.createServer(app);

server.listen(+PORT);

server.on('error', console.error);
server.on('listening', () => {
    const addr = server.address();
    console.log(`Server running on ${addr.address}:${addr.port}`);
});