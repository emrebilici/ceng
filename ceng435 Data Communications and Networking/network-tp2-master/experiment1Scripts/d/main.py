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

class Server():
	def __init__(self,address,port):
		#Initializations(ex. socket, etc.)
		self.address = address
		self.port = port
		self.receivedCounter = 0
		self.sendTimes = []
		self.receiveTimes = []
		self.receivedData = []
		self.expectedSequenceNumber = 0
		self.firstReceivalTime = None
		self.lastReceivalTime = None

	def separateDataPacket(self,receivedPacket):
		sequenceNumber = struct.unpack("I", receivedPacket[2:6])[0]
		dataLength = struct.unpack("H",receivedPacket[6:8])[0]
		sendingTime = struct.unpack("d",receivedPacket[8:16])[0]
		data = receivedPacket[16:]
		return sequenceNumber , dataLength , sendingTime , data

	def checkForChecksum(self, receivedPacket):
		receivedChecksum = struct.unpack("H",receivedPacket[:2])[0] #this is due unpack returning a tuple
		#print("Received Checksum is ", receivedChecksum)
		calculatedChecksum = self.calculateChecksum(receivedPacket[2:])
		#print("Calculated Checksum is : ", calculatedChecksum)
		#print("Checksum result is ", receivedChecksum == calculatedChecksum )
		return receivedChecksum == calculatedChecksum

	def calculateChecksum(self,packetData):
		checksum = 0
		for byteSlice in bytearray(packetData):
			checksum += byteSlice
		checksum &= 0xFFFF
		return checksum

	def createChecksumHeader(self,checksum):
		return struct.pack("H",checksum)
	
	def getChecksumValueFromHeader(self,header):
		return struct.unpack("H" , header[:2])

	def startServer(self):
		#here we create worker threads, and then just call thread.join,

		serverThread = Thread(target = self.serverFunction)
		self.serverThread = serverThread
		serverThread.start()
		
	def waitForServer(self):
		self.serverThread.join()

	def createResponsePacket(self,expectedSequenceNumber):
		sequenceNumberPacked = struct.pack("I",expectedSequenceNumber)
		ack_encoded = "ACK".encode()
		packet = sequenceNumberPacked + ack_encoded
		checksumValue = self.calculateChecksum(packet)
		sendingPacket = self.createChecksumHeader(checksumValue) + packet
		return sendingPacket

	def serverFunction(self):
		# Create a UDP socket
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

		# Bind the socket to the port
		server_address = (self.address, self.port)
		print ('Server is starting up on %s port %s' % server_address)
		stillRunning = True
		sock.settimeout(0.1)
		sock.bind(server_address)
		
		while stillRunning:
			#print ('\n Server waits to receive message')
			try:
				with serverReceivingLock: #deadlock
					receivedPacket, address = sock.recvfrom(1000)
					if receivedPacket:
						if(self.checkForChecksum(receivedPacket)):
							sequenceNumber , dataLength , sendingTime,  data = self.separateDataPacket(receivedPacket)
							if(sequenceNumber == self.expectedSequenceNumber):
								print("Server received Sequence number is :",sequenceNumber)
								if(sequenceNumber == 0):
									self.firstReceivalTime = sendingTime
								#print("Data Length is :",dataLength)
								#print("Sending time is :",sendingTime)
								self.receivedData.append(data)

								#receiveTime = str(time.time())
								#self.receiveTimes.append(receiveTime)
								self.lastReceivalTime = time.time()
								sendingPacket = self.createResponsePacket(self.expectedSequenceNumber)
								print("Sending expected sequence number")
								sendACK = sock.sendto(sendingPacket,address)

								#print ('\nServer received %s bytes from %s' % (len(data), address))
								self.expectedSequenceNumber += 1
			#print (data)
			except socket.timeout:
				if(self.expectedSequenceNumber == 0):
					continue
				sendingPacket = self.createResponsePacket(self.expectedSequenceNumber)
				print("Sending expected sequence number")
				sendACK = sock.sendto(sendingPacket,address)
				if(self.expectedSequenceNumber == expectedNumberOfPackets):
					stillRunning = False
				else:	
					continue
		totalTransferTime = self.lastReceivalTime - self.firstReceivalTime
		print("Total TransferTime is : ", totalTransferTime)
		print ( 'Server closing socket')
		sock.close()
		with open("receivedFile.txt","wb") as outputFile :
			print("Number of received packets is : ",self.expectedSequenceNumber)
			for data in self.receivedData:
				outputFile.write(data)

if __name__ == "__main__":
    #Initialization or target information for our node
    os.system("sudo ntpdate -u pool.ntp.org")
    localAddresses = ['10.10.7.1']
    localPort = 12000
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
