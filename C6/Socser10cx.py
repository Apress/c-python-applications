# socket server 

import socket               # load socket module

skt = socket.socket()         # Create a socket (refer to it as skt in this program)
hostname = socket.gethostname()  # Get local host machine name
print(hostname)  #print the host machine name 
hostip = socket.gethostbyname(hostname) # print host IP address
port = 12357                # Reserve a port (same as client port)
skt.bind((hostname, port))        # Bind the host name and port (establish server status)

skt.listen(5)                 # wait for a client to connect.
while True:
   con, accaddr = skt.accept()     # Accept connection with client.
					# con is the open connection between the server and client, accaddr is the IP address and port number
   print('con is ', con)
   print('accaddr is ', accaddr)

   print('Received connection from', accaddr)
   
   message = "Got your connection" 
   con.send(message.encode())#send message to client to confirm connect

   
   con.close()                # Close connection
   break
	
