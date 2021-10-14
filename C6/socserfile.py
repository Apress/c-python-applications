
# send file to client

import socket                   # Import socket module

port = 3000                     # Reserve a port for your service.
s = socket.socket()             # Create a socket object
host = socket.gethostname()     # Get local machine name
s.bind((host, port))            # Bind to the port
s.listen(5)                     # Now wait for client connection.

print ('Server running')

while True:
    conn, addr = s.accept()     # Establish connection with client.
    print ('Got connection from', addr)
    #print ('conn is ', conn)
    data = conn.recv(1024)
    
    print('Server received', bytes.decode(data))


    filename='pjfile1.txt'
    file = open(filename,'rb')
    line = file.read(1024)
    while (line):
       conn.send(line)
       
       print('Server Received ',bytes.decode(line))
       line = file.read(1024)
    file.close()

    print('Finished sending')
    conn.send(str.encode('Thank you for connecting'))
    conn.close()
    break

    