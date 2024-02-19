import socket
host = '127.0.0.1'
port = 8500

lk = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

lk.connect((host,port))
print("sending data ->  Server-client communication")

lk.send("sending data ->  Server-client communication".encode())

response = lk.recv(1024)