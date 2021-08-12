# Basic example of socket-programming in C

## Overview
We implement an echo protocol in C.
Server and Client will connect to each other, Client will send a sample string to Server and it will get back the same string capitalized.

## Compilation
```
cd ./echo_protocol/server
make
```
```
cd ./echo_protocol/client
make
```


## Execution
Open one terminal for Server.
Navigate to the directory `server` and execute `./server`.
Then, open a new terminal for Client.
Navigate to the directory `client` and execute `./client`.
