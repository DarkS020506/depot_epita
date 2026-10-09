import socket

server = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

host=socket.gethostname()
port = 444

server.bind((host,port))

print(f"Running UDP server on {host}:{port}")
while True:
    client, adress = server.recvfrom(2041)
    print(f"Received connection from {client} {adress}")
    message = "Hello\r\n"
    client.send(message.encode('ascii'),adress)
    print(f"Closed UDP with {client} {adress})
