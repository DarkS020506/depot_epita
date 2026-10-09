import sys
import select
import time

# Import helper functions used for UDP communication
from udp_network import create_udp_socket, bind_socket, send_message, receive_message

# IP address and port where this peer will listen
UDP_IP = "127.0.0.1"
UDP_PORT = 5005

# Create the UDP socket
sock = create_udp_socket()

# Bind the socket to the local IP and port so it can receive messages
bind_socket(sock, UDP_IP, UDP_PORT)

# Variable to store the address (IP, port) of the other peer
peer_addr = None

# Startup message
print("Peer2 UDP chat started. Waiting for messages from Peer1")

# Infinite loop to keep the chat running
is_writing=True
debut=time.time()
while True:

    # Wait for input from either:
    # - the keyboard (sys.stdin)
    # - the network socket (sock)
    readable, _, _ = select.select([sys.stdin, sock], [], [],0.1)
    fin=time.time()
    if (fin-debut)>=5 and is_writing==False:
        print("timeout 5s, relance")
        send_message(sock,message,peer_addr[0],peer_addr[1])
        debut=time.time()

    # Check which input source is ready
    for r in readable:

        # If data arrives from the socket (network message)
        if r == sock:

            # Receive the message and the sender's address
            msg, addr = receive_message(sock)

            # Save the sender's address so we know where to reply
            peer_addr = addr

            # If a valid message was received
            
            charge=msg.split("|")
            if msg:
                if charge[0]!="ACK":
                    # Print the message from Peer1
                    print(f"\nPeer1: {charge[0]}\nSN:{charge[1]}, len:{charge[2]}")
                    ack=int(int(charge[1])+int(charge[2]))
                    message=f"ACK|{ack}"
                    print("send ACK confirmation")
                    send_message(sock, message, peer_addr[0],peer_addr[1])
                    print("\nYou: ",end="",flush=True)
                    is_writing=True
                    break

                else:
                    # Show the prompt again for the user
                    if charge[1]=="correct":
                        is_writing=True
                        break
                    else:
                        Ack=charge[1]
                        if int(Ack)==int(ack_attendu):
                            message="ACK|correct"
                            send_message(sock,message,peer_addr[0],peer_addr[1])
                            print("send ACK correct")
                            is_writing=True
                            break
                        else:
                            message="ACK|incorrect"
                            send_message(sock,message,peer_addr[0],peer_addr[1])
                            print("send ACK incorrect")
                            break

        # If the user types something in the terminal
        elif r == sys.stdin:

            # Only send a message if we already know the peer's address
            if peer_addr:
                # Read the user's message
                message = sys.stdin.readline().strip()
                m_len=len(message)
                SN=ack
                message=f"{message} | {SN} | {m_len}"
                ack_attendu=SN+m_len
                is_writing=False
                debut=time.time()
                # Send the message to the stored peer address
                send_message(sock, message, peer_addr[0], peer_addr[1])

