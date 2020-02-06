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
		packet = self.createSequenceNumberHeader(sequenceNumber) + self.createLengthHeader(len(data)) + self.createSendingTimeHeader() + data
		checksumValue = self.calculateChecksum(packet)
		packet = self.createChecksumHeader(checksumValue) + packet
		return packet
	
	def checkForChecksum(self, receivedPacket):
		receivedChecksum = struct.unpack("H",receivedPacket[:2])[0] #this is due unpack returning a tuple
		#print("Received Checksum is ", receivedChecksum)
		calculatedChecksum = self.calculateChecksum(receivedPacket[2:])
		#print("Calculated Checksum is : ", calculatedChecksum)
		#print("Checksum result is ", receivedChecksum == calculatedChecksum )
		return receivedChecksum == calculatedChecksum

	def separateACKPacket(self,response):
		sequenceNumber = struct.unpack("I", response[2:6])[0]
		data = response[6:]
		return sequenceNumber , data

	def readInputFile(self):
		with open("input.txt", "rb") as fp:
			self.data = fp.read(SENDING_FILE_SIZE)

	def getNextDataPacket(self,beginningPacketNumber):
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
		sock.settimeout(0.1)

		while stillRunning : 
			try:
				while self.currentSequenceNumber < expectedNumberOfPackets :
					#get sending time
					currentPacketArray = []
					tempSequenceNumber = self.currentSequenceNumber
					beginningSequenceNumber = self.currentSequenceNumber
					while (tempSequenceNumber < expectedNumberOfPackets) and (tempSequenceNumber < (beginningSequenceNumber + WINDOW_SIZE)) :
						#print("Creating data packet : ", tempSequenceNumber)
						tempData = self.getNextDataPacket(tempSequenceNumber)
						currentPacketArray.append(self.createWrappedPacket(tempSequenceNumber,tempData))
						tempSequenceNumber += 1
					print ( '\nClient sends ')

					#send it to server
					with clientSendingLock: #use lock before sending
						for currentPacket in currentPacketArray:
							sent = sock.sendto(currentPacket, server_address)
					#self.sentTimes.append(sentTime)
					#wait for r3 ack
					with clientReceivingLock:
						receivedACKPacket, server = sock.recvfrom(1000) # timeout exception
					if receivedACKPacket :
						#receive ack from r3 , so it doesn't flood the network with packets
						if(self.checkForChecksum(receivedACKPacket)):
							sequenceNumber , data = self.separateACKPacket(receivedACKPacket)
							if(data.decode() == "ACK"):						
								#print("ACK received by s")
								print("Client Received ACK for sequence number ", sequenceNumber)
								self.currentSequenceNumber = sequenceNumber
								if(self.currentSequenceNumber == expectedNumberOfPackets):
									print("Expected Sequence ", self.currentSequenceNumber)
									stillRunning = False
					#print ( '\nClient received "%s"' % data )
					#print ("\nRTT in ms is : ", difference*1000)


			except socket.timeout:
				continue
		print ( 'Client closing socket')
		sock.close()

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
	#os.system("sudo ntpdate -u pool.ntp.org")
	numberOfClientThreads = 1
	numberOfServerThreads = 1
	numberOfTries = 1000

	targetAddresses = ['127.0.0.1']
	targetPorts = [12000] 

	clientThreads = []
	serverThreads = []

	for i in range(numberOfServerThreads):
		#Initializes server and client classes
		serverThreads.append(Server(targetAddresses[i],targetPorts[i]))

	
	for i in range(numberOfClientThreads):
		#Initializes server and client classes
		clientThreads.append(Client(targetAddresses[i],targetPorts[i]))


	for i in range(numberOfServerThreads):
		#Runs server and client
		serverThreads[i].startServer()

	for i in range(numberOfClientThreads):
		#Runs server and client
		clientThreads[i].startClient()

	for i in range(numberOfServerThreads):
		serverThreads[i].waitForServer()

	#main thread waits for client and server threads to finish
	for i in range(numberOfClientThreads):
		clientThreads[i].waitForClient()
	
