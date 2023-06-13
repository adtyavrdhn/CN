import socket

host = '127.0.0.1'
port = 8500

lk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lk.bind((host, port))

lk.listen()  # Start listening for client connections

while True:
    client, address = lk.accept()
    print("Connected to client:", address)

    while True:
        response = client.recv(1024)

        if not response:
            break

        print("Text received is:\n" + response.decode())
        upper_response = response.decode().upper()
        client.send(upper_response.encode())

    client.close()
