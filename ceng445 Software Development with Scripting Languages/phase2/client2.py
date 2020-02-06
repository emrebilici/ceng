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

# {"pId":2, "request": "join", "name": "mustafa"}
# {"pId":2, "request": "ready"}

# SERVER = "127.0.0.1"
# PORT = 8080
# client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client.connect((SERVER, PORT))
# #client.sendall(bytes("This is from Client", 'UTF-8'))

def main():
    game1 = game.Game("deneme6.json")
    # name = input("name:")
    # id = int(input("id:"))
    player1 = Client()
    #player1 = player.Player(1, "emre")
    #pickle.dumps(player1)



def test9():
    print("-------------Test8-------------\n")
    game1 = game.Game("deneme6.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
    player4 = player.Player(4, "dorduncu")
    player1.join(game1)
    player2.join(game1)
    player3.join(game1)
    player4.join(game1)
    if player1 in game1.players and player2 in game1.players and player3 in game1.players and player4 in game1.players:
        print("joined players are true")

    player1.ready()
    player3.ready()
    player2.ready()
    player4.ready()
    print("firstcollect game. collect no: 5. There are 3 players ")

    if game1.winner == None:
        return "There is no winner since all of them lost their money."
    if game1.winner.pickedArt == game1.gameTypeValue:
        print("For test8: player {0} is winner reaching the desiring artifact number {1} ".format(game1.winner, game1.gameTypeValue))
    if game1.winner:
        print("For test8: player {0} is winner but it did not reach the desiring arifact number {1}".format(game1.winner, game1.gameTypeValue))


if __name__ == '__main__':
    main()
