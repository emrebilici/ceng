import time
import socket
import sys
from threading import Thread

class Client(Thread):
    def __init__(self,address,port,targetName,numberOfTries):
        #Part will be used for initializations(ex. socket, etc.)
        self.differenceAccumulator = 0
        self.address = address
        self.port = port
        self.numberOfTries = numberOfTries
        self.currentName = 'r2'
        self.targetName = targetName

    def startClient(self):
        #Create thread and start it
        clientThread = Thread(target = self.clientFunction)
        self.clientThread = clientThread
        clientThread.start()

    def waitForClient(self):
        #Allows us to wait for it in main
        self.clientThread.join()


    def clientFunction(self):
        # Create a UDP socket
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server_address = (self.address, self.port)

        currentTries = 0

        message = b'UDP MESSAGE'
        try:
            while currentTries < self.numberOfTries : 
                #print ( '\nClient sends "%s"' % message)
                sentTime = time.time()
                sent = sock.sendto(message, server_address)

                # Receive response
                #print ( '\nClient waits to receive' )
                data, server = sock.recvfrom(4096)
                receiveTime = time.time()
                #rtt calculations
                difference = receiveTime - sentTime
                self.differenceAccumulator += difference
                #print ( '\nClient received "%s"' % data )
                #print ("\nRTT in ms is : ", difference*1000)
                currentTries += 1

        finally:
            with open("link_costs.txt","a") as outputFile :
                differenceAverage = self.differenceAccumulator/self.numberOfTries
                outputFile.write(self.currentName + "-" + self.targetName +" : " + str(differenceAverage) + "\n")
            print ( 'Client closing socket')
            sock.close()

class Server():
    def __init__(self,address,port):
        #Initializations(ex. socket, etc.)
        self.address = address
        self.port = port
    
    def startServer(self):
        #here we create worker threads, and then just call thread.join,

        serverThread = Thread(target = self.serverFunction)
        self.serverThread = serverThread
        serverThread.start()
        
    def waitForServer(self):
        self.serverThread.join()


    def serverFunction(self):
        # Create a UDP socket
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        # Bind the socket to the port
        server_address = (self.address, self.port)
        print ('Server is starting up on %s port %s' % server_address)
        sock.settimeout(60)

        sock.bind(server_address)
        while True:
            #print ('\n Server waits to receive message')
            data, address = sock.recvfrom(4096)
            
            #print ('\nServer received %s bytes from %s' % (len(data), address))
            #print (data)
            
            if data:
                sent = sock.sendto(data, address)
                #print ( '\nServer sent %s bytes back to %s' % (sent, address) )


if __name__ == "__main__":
    """ Server Initializations
    --------------------------
    """
    #Interface addreses for our server threads to listen
    localAddresses = ['10.10.8.2','10.10.6.1']
    #For convenience we have just decided to use consecutive ports
    localPort = 15000
    numberOfServerThreads = 2

    """ Client Initializations
    --------------------------
    """
    #Number of messages that will be sent between each node
    numberOfTries = 1000
    numberOfClientThreads = 2

    #Target Addresses for client threads to send messages to
    targetAddresses = ['10.10.5.2','10.10.2.2'] 
    #Target Ports for client threads to send messages to
    targetPorts = [10001,20001]
    #Target Names for client threads, for outputting purposes
    targetNames = ['d','s']

    serverThreads = []
    clientThreads = []

    # Even though this parts should be seperate for server and client threads,
    # Since numberOfClients == numberOfServers this is not a problem

    for i in range(numberOfClientThreads):
    #Initializes server and client threads
        serverThreads.append(Server(localAddresses[i],localPort+i))
        clientThreads.append(Client(targetAddresses[i],targetPorts[i],targetNames[i],numberOfTries))

    for i in range(numberOfClientThreads):
    #Runs server and client threads
        serverThreads[i].startServer()
        clientThreads[i].startClient()

    #Main thread waits for client and server threads to finish
    for i in range(numberOfClientThreads):
        serverThreads[i].waitForServer()
        clientThreads[i].waitForClient()
