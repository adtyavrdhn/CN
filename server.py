import socket


def server_program():
    host = socket.gethostname()
    port = 5566

    server_socket = socket.socket()
    server_socket.bind((host, port))

    server_socket.listen(2)

    conn, addr = server_socket.accept()

    print("Connected to " + str(addr))

    while True:
        data = conn.recv(1024).decode()

        if not data:
            break
        else:
            print("Message from client: \n" + data)
            data = data.upper()
            conn.send(data.encode())

    conn.close()


if __name__ == '__main__':
    server_program()
