#from threading import Thread
import socket
import sys
from threading import Thread

class Repeater():
    def __init__(self,sourceAddress,sourcePort,destinationAddress,destinationPort):
        #Initializations(ex. socket, etc.)
        self.sourceAddress = sourceAddress
        self.destinationAddress = destinationAddress
        self.sourcePort = sourcePort
        self.destinationPort = destinationPort
    
    def startRepeater(self):
        #here we create worker threads, and then just call thread.join,

        self.repeaterThread = Thread(target = self.repeaterFunction)
        self.repeaterThread.start()
        
    def waitForRepeater(self):
        self.repeaterThread.join()

    def repeaterFunction(self):
        # Create a UDP socket
        sourceSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        destinationSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        # Bind the socket to the port
        source_address = (self.sourceAddress, self.sourcePort)
        destination_address = (self.destinationAddress, self.destinationPort)
        #print ('Repeater is starting up on %s port %s' % server_address)
        sourceSock.settimeout(60)
        destinationSock.settimeout(60)
        sourceSock.bind(source_address)
        print ('\n Repeater ports are bound and waits to receive message')
        while True:
            while True:
                #Waits for source packet
                data, address = sourceSock.recvfrom(4096)
                #print ('\n Repeater received %s bytes from source %s' % (len(data), address))
                #print (data)
                
                if data:
                    #if receives packet , send it to destination, then start waiting for response
                    sent = destinationSock.sendto(data, destination_address)
                    #print ( '\Repeater sent %s bytes to destination %s' % (sent, address) )
                    break
            while True:
                #waits for destination packet
                #print ('\n Repeater waits to receive message')
                data, address = sourceSock.recvfrom(4096)
                
                #print ('\n Repeater received %s bytes from destination %s' % (len(data), address))
                #print (data)
                
                if data:
                    #Just pass it back to the source

                    sent = sourceSock.sendto(data, source_address)
                    #print ( '\Repeater sent %s bytes to source %s' % (sent, address) )
                    break

if __name__ == "__main__":
    #Initialization or target information for our node
    localAddresses = ['10.10.3.2']
    localPorts = [12000]

    numberOfTries = 1000

    numberOfRepeaterThreads = 1

    #Only clients use targetAddresses
    targetAddresses = ['10.10.7.1'] 
    targetPorts = [12001] 

    repeaterThreads = []

    for i in range(numberOfRepeaterThreads):
        #Initializes server and client classes
        repeaterThreads.append(Repeater(localAddresses[i],localPorts[i],targetAddresses[i],targetPorts[i]))

    for i in range(numberOfRepeaterThreads):
        #Runs server and client
        repeaterThreads[i].startRepeater()

    #main thread waits for client and server threads to finish
    for i in range(numberOfRepeaterThreads):
        repeaterThreads[i].waitForRepeater()
