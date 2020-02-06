import time
import socket
import sys
from threading import Thread
import os

class Client(Thread):
    def __init__(self,address,port,targetName,numberOfTries):
        #Part will be used for initializations(ex. socket, etc.)
        self.differenceAccumulator = 0
        self.address = address
        self.port = port
        self.numberOfTries = numberOfTries
        self.currentName = 's'
        self.targetName = targetName
        self.sentTimes = []

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

        try:
            while currentTries < self.numberOfTries : 
                #print ( '\nClient sends "%s"' % message)
                sentTime = str(time.time())
                encodedSentTime = sentTime.encode()
                sent = sock.sendto(encodedSentTime, server_address)
                self.sentTimes.append(sentTime)
                data, server = sock.recvfrom(4096)
                if data :
                    print("ACK received by s")

                #print ( '\nClient received "%s"' % data )
                #print ("\nRTT in ms is : ", difference*1000)
                currentTries += 1

        finally:
            with open("send_times.txt","a") as outputFile :
                for i in range( len(self.sentTimes) ):
                    outputFile.write(str(self.sentTimes[i]) + "\n")
            print ( 'Client closing socket')
            sock.close()

    
if __name__ == "__main__":
    #Initialization or target information for our node
    os.system("sudo ntpdate -u pool.ntp.org")
    numberOfClientThreads = 1
    numberOfTries = 1000

    targetAddresses = ['10.10.3.2'] #TODO addresses of s , d, r2
    targetPorts = [12000] #TODO addresses of s , d, r2
    targetNames = ['r3']

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
