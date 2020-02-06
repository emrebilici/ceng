import time
import socket
import sys
from threading import Thread

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
    #Initialization or target information for our node
    localAddresses = ['10.10.1.1','10.10.2.2','10.10.3.1']
    localPort = 20000
    numberOfServerThreads = 3

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
