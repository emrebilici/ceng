import time
import socket
import sys
from threading import Thread , Lock
import os
import struct

#constants for packet and file size
SENDING_FILE_SIZE = 5000000
PACKET_SIZE = 900
expectedNumberOfPackets = (SENDING_FILE_SIZE // PACKET_SIZE) + 1

TIME_OUT_LIMIT = 10

WINDOW_SIZE = 10

clientSendingLock = Lock()
clientReceivingLock = Lock()

class Client(Thread):
	def __init__(self,address,port):
		#Part will be used for initializations(ex. socket, etc.)
		self.differenceAccumulator = 0
		self.address = address
		self.port = port
		self.currentName = 's'
		self.sentTimes = []
		self.data = None
		self.currentSequenceNumber = 0
		self.lastReceivedTime = time.time()

	def calculateChecksum(self,packetData):
		checksum = 0
		for byteSlice in bytearray(packetData):
			checksum += byteSlice
		checksum &= 0xFFFF
		return checksum
	
	def createChecksumHeader(self,checksum):
		return struct.pack("H",checksum)

	def createLengthHeader(self,dataLength):
		return struct.pack("H",dataLength)

	def createSequenceNumberHeader(self,sequenceNumber):
		return struct.pack("I",sequenceNumber)

	def createSendingTimeHeader(self):
		return struct.pack("d",time.time())

	def createWrappedPacket(self,sequenceNumber,data):
		#wraps sequence no and data into a packet
		packet = self.createSequenceNumberHeader(sequenceNumber) + self.createLengthHeader(len(data)) + self.createSendingTimeHeader() + data
		checksumValue = self.calculateChecksum(packet)
		packet = self.createChecksumHeader(checksumValue) + packet
		return packet
	
	def checkForChecksum(self, receivedPacket):
		receivedChecksum = struct.unpack("H",receivedPacket[:2])[0] #this is due unpack returning a tuple
		calculatedChecksum = self.calculateChecksum(receivedPacket[2:])
		return receivedChecksum == calculatedChecksum

	def separateACKPacket(self,response):
		sequenceNumber = struct.unpack("I", response[2:6])[0]
		data = response[6:]
		return sequenceNumber , data

	def readInputFile(self):
		with open("input.txt", "rb") as fp:
			self.data = fp.read(SENDING_FILE_SIZE)

	def getNextDataPacket(self,beginningPacketNumber):
		#seperates data file into 900 byte chunks
		beginningIndex = 900 * beginningPacketNumber
		endingIndex = 900 * (beginningPacketNumber+1)
		if(endingIndex >= SENDING_FILE_SIZE):
			endingIndex = SENDING_FILE_SIZE 
		return self.data[beginningIndex : endingIndex]

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
		self.readInputFile()
		stillRunning = True
		sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		server_address = (self.address, self.port)

		print("Client is starting up")
		sock.settimeout(0.1) # important for resends

		while stillRunning : 
			try:
				while self.currentSequenceNumber < expectedNumberOfPackets :
					#create packets as much as WINDOW_SIZE
					currentPacketArray = []
					tempSequenceNumber = self.currentSequenceNumber
					beginningSequenceNumber = self.currentSequenceNumber
					while (tempSequenceNumber < expectedNumberOfPackets) and (tempSequenceNumber < (beginningSequenceNumber + WINDOW_SIZE)) :
						tempData = self.getNextDataPacket(tempSequenceNumber)
						currentPacketArray.append(self.createWrappedPacket(tempSequenceNumber,tempData))
						tempSequenceNumber += 1

					#send it to server
					with clientSendingLock:
						for currentPacket in currentPacketArray:
							sent = sock.sendto(currentPacket, server_address)
					#wait for ack
					with clientReceivingLock:
						receivedACKPacket, server = sock.recvfrom(1000)
					#if receives a packet
					if receivedACKPacket :
						#and its not corrupted
						if(self.checkForChecksum(receivedACKPacket)):
							sequenceNumber , data = self.separateACKPacket(receivedACKPacket)
							#make sure that its ACK
							if(data.decode() == "ACK"):						
								self.lastReceivedTime = time.time() # for timeout 
								print("Client Received ACK for sequence number ", sequenceNumber)
								self.currentSequenceNumber = sequenceNumber
								if(self.currentSequenceNumber == expectedNumberOfPackets):
									#stopping condition
									stillRunning = False

			except socket.timeout:
				if time.time() - self.lastReceivedTime > TIME_OUT_LIMIT:
					#closing timeout
					break
				continue
		print ( 'Client closing socket')
		sock.close()


if __name__ == "__main__":
	#Initialization or target information for our node
	os.system("sudo ntpdate -u pool.ntp.org")
	numberOfClientThreads = 1

	targetAddresses = ['10.10.3.2']
	targetPorts = [12000]

	clientThreads = []
	
	for i in range(numberOfClientThreads):
		#Initializes server and client classes
		clientThreads.append(Client(targetAddresses[i],targetPorts[i]))

	for i in range(numberOfClientThreads):
		#Runs server and client
		clientThreads[i].startClient()

	#main thread waits for client and server threads to finish
	for i in range(numberOfClientThreads):
		clientThreads[i].waitForClient()
	
