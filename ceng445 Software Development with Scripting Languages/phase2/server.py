import socket, threading, pickle,player,json
import game

class Server():
    #game1 = game.Game("deneme6.json")
    def __init__(self):
        LOCALHOST = "127.0.0.1"
        PORT = 8080
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server.bind((LOCALHOST, PORT))
        #super(Server, self).__init__("deneme6.json")
        game1 = game.Game("deneme6.json")
        print("Server started")
        print("Waiting for client request..")
        #print("{0}".format(self.gameType))
        self.started = 0
        while True:
            server.listen(5)
            clientsock, clientAddress = server.accept()
            newthread = self.ClientThread(clientAddress, clientsock, game1)
            newthread.start()

    class ClientThread(threading.Thread):
        def __init__(self, clientAddress, clientsocket, serv):
            self.serv = serv    # yanlis bir method gibi. gamein fonksiyonlarını burada kullanabilmek icin yapilmis. bunun yerine server classı yapmazsın. game objesini initte verirsin.
            self.clientsocket = clientsocket
            self.clientAddress = clientAddress
            self.csocket = clientsocket
            threading.Thread.__init__(self)
            print ("New connection added: ", self.clientAddress)

        def run(self):
            print ("Connection from : ", self.clientAddress)
            print(self.serv.gameTypeValue)
            self.csocket.sendall(bytes("hi", 'UTF-8'))
            msg = ''
            data =b""

            while True:
                data = self.csocket.recv(1024)
                #msg = data
                msg = data.decode()
                #print(msg)
                if data == b"":
                    print("data bos")
                    break
                elif msg[0] == '{':
                    #print(msg)
                    msg1 = eval(msg)
                    print(msg1["request"])
                    if msg1["request"] == "join":
                        print(msg)
                        p1 = player.Player(msg1["pId"], msg1["name"])
                        self.serv.join(p1)
                        self.csocket.sendall(bytes("joined", 'UTF-8'))

                    elif msg1["request"] == "ready":

                        readyPlayer =list(filter(lambda x: x.id == msg1["pId"], self.serv.players))[0]
                        if readyPlayer:
                            self.serv.ready(readyPlayer)
                        self.csocket.sendall(bytes("ready", 'UTF-8'))
                        break

                    elif msg1["request"] == "notify":
                        self.csocket.sendall(bytes(str(self.serv.state()), 'UTF-8'))
                    # elif msg1["request"] == "choice":
                    #     if msg1["value"] == "True":
                    #         choicePlayer = list(filter(lambda x: x.id == msg1["pId"], self.serv.players))[0]
                    #         self.serv.pick(choicePlayer, True)
                    #     else:
                    #         choicePlayer = list(filter(lambda x: x.id == msg1["pId"], self.serv.players))[0]
                    #         self.serv.pick(choicePlayer, False)
                print(msg)
            self.csocket.close()
            print(self.serv.players)

            #print ("from client", msg)

            #print ("Client at ", self.clientAddress , " disconnected...")
            

if __name__ == '__main__':
    Server()
