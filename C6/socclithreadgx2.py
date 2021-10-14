import socket
import os

mypid = os.getpid()

print('Client My pid is', mypid)

ClientSocket = socket.socket()

host = socket.gethostname()     # Get local machine name

port = 1234

print('Waiting for connection')
ClientSocket.connect((host, port)) #connect to Server

Response = ClientSocket.recv(1024)
print(ClientSocket) # show server and client addresses
while True:
    Input = input('Enter message: ') #ask user to enter their message
    ClientSocket.send(str.encode(Input)) #send message to socket
    Response = ClientSocket.recv(1024) #get response from server
   

    if( Response.decode()) =='Server says: windup':
        # if client wants to disconnect from server, the user types ‘windup’
        break
    print(Response.decode()) 
    


ClientSocket.close()
