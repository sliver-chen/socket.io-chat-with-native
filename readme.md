# socket.io-chat-with-native

```
shows that how does native client chat with node.js server by using socket.io 
```

## make and test

client:
socket.io-chat-with-native depend on socket.io-poco  
please install it first.  

and cd build  
    cmake .. && make -j4  

server:
    cd server  
    npm install  
    node index.js  

then you can input any from keyboard to chat with other.
