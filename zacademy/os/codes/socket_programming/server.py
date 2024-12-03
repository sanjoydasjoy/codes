import socket

PORT = 8080

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

server_socket.bind(('0.0.0.0', PORT))
server_socket.listen(3)

print(f"Server listening on port {PORT}")

client_socket, addr = server_socket.accept()
print(f"Accepted connection from {addr}")

data = client_socket.recv(1024)
print(data.decode('utf-8'))

hello_message = "Hello from server"
client_socket.sendall(hello_message.encode('utf-8'))
print("Hi this is server!!")

client_socket.close()
server_socket.close()
