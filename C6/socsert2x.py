# Socket Server Program

import time, socket, sys

server_port = 1000

server_socket = socket.socket()
host_name = socket.gethostname()
server_socket.bind((host_name ,server_port))

server_socket.listen(1)
print ("Server is loaded")
connection_socket, address = server_socket.accept()
while True:
    sentence = connection_socket.recv(2048).decode()
    print('>> ',sentence)
    message = input(">> ")
    connection_socket.send(message.encode())
    if(message == 'windup'):
       connection_socket.close()
       break
    