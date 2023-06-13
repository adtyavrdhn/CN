import socket

host = '127.0.0.1'
port = 8500

lk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lk.connect((host, port))

while True:
    data = input("Enter data ('q' to quit): ")
    if data == 'q':
        break

    lk.send(data.encode())

    response = lk.recv(1024)

    if response != "":
        print("Text received is:\n" + response.decode())

lk.close()
