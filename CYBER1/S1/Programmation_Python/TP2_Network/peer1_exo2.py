import sys
import select
import random

SN=random.randint(0,100)


# Import helper functions for UDP communication
from udp_network import create_udp_socket, send_message, receive_message

# IP address and port where the peer will send messages
UDP_IP = "127.0.0.1"
UDP_PORT = 5005

# Create and configure the UDP socket using the helper function
sock = create_udp_socket()

# Display startup message for the chat
print("Peer1 UDP chat started")

# Show the prompt for the user to type a message
print("You: ", end="", flush=True)

# Infinite loop to keep the chat running
while True:

    # Wait until either:
    # - the user types something (sys.stdin)
    # - a message arrives on the socket (sock)
    readable, _, _ = select.select([sys.stdin, sock], [], [])

    # Iterate over the sources that are ready to read
    for r in readable:

        # If the input comes from the keyboard
        if r == sys.stdin:
            # Read the user's message from the terminal
            message = sys.stdin.readline().strip()
            m_len=len(message)
            message=f"{message} | {SN} | {m_len}"
            ack_attendu=SN+m_len

            # Send the message via UDP to the specified IP and port
            send_message(sock, message, UDP_IP, UDP_PORT)

        # If the input comes from the network socket
        elif r == sock:
            # Receive a message from the UDP socket
            msg, _ = receive_message(sock)
            charge=msg.split("|")
            if charge[0]=="ACK":
                if charge[1]=="correct":
                    break
                else:
                    Ack=charge[1]
                    if int(Ack)==int(ack_attendu):
                        message="ACK|correct"
                        send_message(sock, message, UDP_IP, UDP_PORT)
                        print("send ACK correct")
                        break
                    else:
                        message="ACK|incorrect"
                        send_message(sock, message, UDP_IP, UDP_PORT)
                        print("send ACK incorrect")
                        break

            # If a valid message was received
            else:
                # Print the message from the other peer
                print(f"\nPeer2: {charge[0]}\nSN:{charge[1]}, len{charge[2]}")
                ack=int(int(charge[1])+int(charge[2]))
                message=f"ACK|{ack}"
                print("send ACK confirmation")
                send_message(sock,message, UDP_IP, UDP_PORT)
                print("\nYou: ", end="",flush=True)
                break
