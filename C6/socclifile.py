# Socket Client Program
# receive file from server
# and write it to a new file

import socket                   # Import socket module

s = socket.socket()             # Create a socket object
host = socket.gethostname()     # Get local machine name
port = 3000                     # Reserve a port for your service.

s.connect((host, port))
s.send(str.encode("Client connected"))

with open('pjrecfile', 'wb') as file:
    print ('file opened')
    while True:
        print('receiving data from server')
        data = s.recv(1024)
        print('data=%s', (data))
        if not data:
            break
        # write data to a file
        file.write(data)

file.close()
print('Received file from server')
s.close()
print('connection closed')