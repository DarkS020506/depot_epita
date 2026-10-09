import socket

server = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM) #UDP: socket.SOCK_DGRAM

host = socket.gethostname()
port = 445

server.bind((host, port))
server.listen(5) #UDP: retirer

print(f"Running TCP server on {host}:{port}")
while True:
    client, address = server.accept()#UDP: recvfrom(2041)
    print(f"Received connection from {client} {address}")
    message = "Hello!\r\n"
    client.send(message.encode('ascii')) #server.sendto(message.encode('ascii'),adress)
    print(f"Sent TCP to {client} {address}")
    client.close() #retirer
    print(f"Closed TCP with {client} {address}")

