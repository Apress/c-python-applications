import socket	# Import socket module
from _thread import * # thread software 

import os

mypid = os.getpid()

print('Server My pid is', mypid)


ServerSocket = socket.socket()

host = socket.gethostname()     # Get local machine name

port = 1234
ThreadCount = 0	#count of how many clients have connected
ServerSocket.bind((host, port))

print('Waiting for Client connect')
ServerSocket.listen(5)


def threadcli(cliconn):
    print("cliconn")
    print(cliconn)
        
    #connection.sendall(str.encode('Connect'))
    cliconn.sendall(str.encode('Connect'))
    while True:
        
        data = cliconn.recv(2048)
        
        reply = 'Server says: ' + data.decode()
        if not data:
            break
        
        cliconn.sendall(str.encode(reply))
    
    cliconn.close()

while True:
    Cli, addr = ServerSocket.accept()
    print('Connected to: ' + addr[0] + ':' + str(addr[1]))
    print(Cli) # show server and client addresses
    start_new_thread(threadcli, (Cli, )) #function imported from  ‘_thread’
						# This calls local function ‘threadcli’
						# Each threaded client stays within its own
						# ‘threaded_client’ function 
    

    ThreadCount += 1 #add 1 to number of connected clients
    print('Thread Number: ' + str(ThreadCount))
ServerSocket.close()
