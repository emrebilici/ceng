from threading import Thread
import socket
import sys
import time
import ntplib

class Client(Thread):
    def __init__(self,address,port,numberOfTries):
        #Part will be used for initializations(ex. socket, etc.)
        self.differenceAccumulator = 0
        self.address = address
        self.port = port
        self.numberOfTries = numberOfTries
        self.name = "localTester"
        self.ntpClient = ntplib.NTPClient()

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
                sentTime = self.ntpClient.request('europe.pool.ntp.org', version=3)
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
                outputFile
            print ( 'Client closing socket')
            sock.close()