var io = require('socket.io').listen(3000);


io.on('connection', function(socket) {
    console.log("-- " + socket.id + " connected --");
    var readline = require('readline');
    var r1 = readline.createInterface(process.stdin, process.stdout);

    r1.setPrompt('test');
    r1.prompt();

    r1.on('line', function(line) {
        socket.emit('message', line.trim());
        r1.prompt();
    });

    socket.on('message', function(message) {
        console.log(message);
    });  
    socket.on('disconnect', function(socket) {
        console.log("-- " + socket.id + " disconnect --");
    });
});
