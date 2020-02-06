from Server import Server
from Client import Client
import time
if __name__ == "__main__":
    #Initialization or target information for our node
    localAddress = 'localhost'
    localPort = 10000
    numberOfTries = 1000

    numberOfServerThreads = 1
    numberOfClientThreads = 1

    #Only clients use targetAddresses
    targetAddresses = ['localhost'] #TODO addresses of s , d, r2
    targetPorts = [10000] #TODO addresses of s , d, r2

    serverThreads = []
    clientThreads = []

    for i in range(numberOfClientThreads):
        #Initializes server and client classes
        serverThreads.append(Server(localAddress,localPort+i))
        clientThreads.append(Client(targetAddresses[i],targetPorts[i],numberOfTries))

    for i in range(numberOfClientThreads):
        #Runs server and client
        serverThreads[i].startServer()
        clientThreads[i].startClient()

    #main thread waits for client and server threads to finish
    for i in range(numberOfClientThreads):
        serverThreads[i].waitForServer()
        clientThreads[i].waitForClient()
