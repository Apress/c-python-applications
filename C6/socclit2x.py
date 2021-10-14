# Socket Client Program

import time, socket, sys

server_name = socket.gethostname()
server_port = 1000

client_socket = socket.socket()
host_name = socket.gethostname()

client_socket.connect((server_name,server_port))
while True:
    sentence = input(">> ")
    client_socket.send(sentence.encode())
    message = client_socket.recv(2048)
    print (">> ", message.decode())
    if(sentence == 'windup'):
       client_socket.close()
       break
