import socket
host = '127.0.0.1'
port = 8500

lk = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
lk.bind((host,port))

while True:
    lk.listen()
    client,address = lk.accept()
    response = client.recv(1024)

    if response != "":
        print("Text received is:" + response.decode())

    print("Text in uppercase:" + (response.decode()).upper())

client.close()        