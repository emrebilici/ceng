import time
import socket
import sys
from threading import Thread
import os

class Server():
    def __init__(self,address,port):
        #Initializations(ex. socket, etc.)
        self.address = address
        self.port = port
        self.receivedCounter = 0
        self.sendTimes = []
        self.receiveTimes = []
    
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
            try:
                data, address = sock.recvfrom(4096)
                if data:
                    receiveTime = time.time()
                    self.sendTimes.append(float(data.decode()))
                    self.receiveTimes.append(receiveTime)
                #print ('\nServer received %s bytes from %s' % (len(data), address))
            #print (data)
            except socket.timeout:
                break
        with open("difference_times.txt","a") as outputFile :
            for i in range( len(self.receiveTimes) ):
                difference = self.receiveTimes[i]-self.sendTimes[i]
                outputFile.write(str(difference) + "\n")
        print ( 'Server closing socket')
        sock.close()



if __name__ == "__main__":
    #Initialization or target information for our node
    os.system("sudo ntpdate -u pool.ntp.org")
    localAddresses = ['10.10.7.1']
    localPort = 12001
    numberOfServerThreads = 1

    serverThreads = []

    for i in range(numberOfServerThreads):
        #Initializes server and client classes
        serverThreads.append(Server(localAddresses[i],localPort+i))

    for i in range(numberOfServerThreads):
        #Runs server and client
        serverThreads[i].startServer()

        #main thread waits for client and server threads to finish
    for i in range(numberOfServerThreads):
        serverThreads[i].waitForServer()
