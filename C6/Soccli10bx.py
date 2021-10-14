# socket client 

import socket               # load socket module

skt = socket.socket()         # Create a socket 
hostname = socket.gethostname() # Get local machine name
port = 12357                # Reserve a port (must be same as socser10a)

skt.connect((hostname, port)) # connect to the server


data = skt.recv(1024) # receive each line of data from server

print('data is ',data.decode()) #  print the line of data received

skt.close()                     # Close connection
