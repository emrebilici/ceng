from threading import Thread
import socket
import sys
import time

class Client(Thread):
    def __init__(self,address,port,targetName,numberOfTries):
        #Part will be used for initializations(ex. socket, etc.)
        self.differenceAccumulator = 0
        self.address = address
        self.port = port
        self.numberOfTries = numberOfTries
        self.currentName = 'r3'
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

if __name__ == "__main__":
    #Initialization or target information for our node

    numberOfClientThreads = 3
    numberOfTries = 1000

    targetAddresses = ['10.10.3.1','10.10.6.1','10.10.7.1'] #TODO addresses of s , d, r2
    targetPorts = [20002,15001,10002] #TODO addresses of s , d, r2
    targetNames = ['s','r2','d']

    clientThreads = []

    for i in range(numberOfClientThreads):
        #Initializes server and client classes
        clientThreads.append(Client(targetAddresses[i],targetPorts[i],targetNames[i],numberOfTries))

    for i in range(numberOfClientThreads):
        #Runs server and client
        clientThreads[i].startClient()

    #main thread waits for client and server threads to finish
    for i in range(numberOfClientThreads):
        clientThreads[i].waitForClient()
