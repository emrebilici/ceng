import socket, threading, pickle
import player, game, json
import time


class Client():
    def __init__(self):
        SERVER = "127.0.0.1"
        PORT = 8080
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect((SERVER, PORT))
        #p1 = player.Player(id, name)
        self.client.sendall(bytes("This is from Client", 'UTF-8'))

        while True:
            in_data = self.client.recv(1024)
            print("From Server :", in_data.decode())
            out_data = input()
            #jout = json.dumps(out_data)
            self.client.send(bytes(out_data,"utf-8"))
            if out_data == 'bye':
                break
        self.client.close()

# {"pId":3, "request": "join", "name": "ucuncu"}
# {"pId":3, "request": "ready"}

def main():
    game1 = game.Game("deneme6.json")

    player1 = Client()
    #player1 = player.Player(1, "emre")
    #pickle.dumps(player1)


if __name__ == '__main__':
    main()
