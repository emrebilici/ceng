import time
import socket
import sys
from threading import Thread , Lock
import os
import struct

SENDING_FILE_SIZE = 5000000
PACKET_SIZE = 900
expectedNumberOfPackets = (SENDING_FILE_SIZE // PACKET_SIZE) + 1

WINDOW_SIZE = 10

serverSendingLock = Lock()
serverReceivingLock = Lock()

#from threading import Thread
import socket
import sys
from threading import Thread

class Repeater():
    def __init__(self,sourceAddress,sourcePort,destinationAddress,destinationPort,isForward):
        #Initializations(ex. socket, etc.)
        self.sourceAddress = sourceAddress
        self.destinationAddress = destinationAddress
        self.sourcePort = sourcePort
        self.destinationPort = destinationPort
        self.isForward = isForward
    
    def startRepeater(self):
        #here we create worker threads, and then just call thread.join,

        self.repeaterThread = Thread(target = self.repeaterFunction)
        self.repeaterThread.start()
        
    def waitForRepeater(self):
        self.repeaterThread.join()

    def repeaterFunction(self):
        # Create a TCP/IP socket
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
                data, address = sourceSock.recvfrom(1000)
                #print ('\n Repeater received %s bytes from source %s' % (len(data), address))
                #print (data)
                
                if data:
                    #if receives packet , send it to destination, then start waiting for response
                    if self.isForward:
                        print("Goes forward : R1 received , passing it to d")
                    else:
                        print("Goes backward : R1 received , passing it to s")
                    sent = destinationSock.sendto(data, destination_address)
                    #print ( '\Repeater sent %s bytes to destination %s' % (sent, address) )
                    break

if __name__ == "__main__":
    #Initialization or target information for our node
    localInterfaceAddresses = ['10.10.1.2','10.10.4.1']
    portNo  = 12000

    numberOfRepeaterThreads = 2

    #Only clients use targetAddresses
    targetAddresses = ['10.10.4.2','10.10.1.1']
    isForward = [True,False]

    repeaterThreads = []

    repeaterThreads.append(Repeater(localInterfaceAddresses[0],portNo,targetAddresses[0],portNo,isForward[0]))
    repeaterThreads.append(Repeater(localInterfaceAddresses[1],portNo,targetAddresses[1],portNo,isForward[1]))

    for i in range(numberOfRepeaterThreads):
        #Runs server and client
        repeaterThreads[i].startRepeater()

    #main thread waits for client and server threads to finish
    for i in range(numberOfRepeaterThreads):
        repeaterThreads[i].waitForRepeater()