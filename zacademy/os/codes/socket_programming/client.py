import socket

PORT = 8080

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('127.0.0.1', PORT)

try:
    client_socket.connect(server_address)
except Exception as e:
    print(f"Connection failed: {e}")
    exit()

hello_message = "Hello from client"
client_socket.sendall(hello_message.encode('utf-8'))
print("hi this is client!")

data = client_socket.recv(1024)
print(data.decode('utf-8'))

client_socket.close()
