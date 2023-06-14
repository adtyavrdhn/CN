import socket


def client_program():
    host = socket.gethostname()
    port = 5566

    client_socket = socket.socket()
    client_socket.connect((host, port))

    msg = input("Enter your string: \n")

    while msg.lower().strip() != 'end':
        client_socket.send(msg.encode())

        data = client_socket.recv(1024).decode()

        print("Message recieved from server: \n" + data)

        msg = input("Enter your string: \n")

    client_socket.close()


if __name__ == '__main__':
    client_program()
