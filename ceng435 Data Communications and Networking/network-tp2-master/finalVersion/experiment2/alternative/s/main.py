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

clientAccessLock = Lock()
stillRunning = True

forwardGoingIndex = 0
backwardGoingIndex = 5555
TIME_OUT_LIMIT = 10

class Client(Thread):
	def __init__(self,targetAddress,port,localAddress,sendsInOrder):
		#Part will be used for initializations(ex. socket, etc.)
		self.differenceAccumulator = 0
		self.targetAddress = targetAddress
		self.localAddress = localAddress
		self.port = port
		self.currentName = 's'
		self.sentTimes = []
		self.data = None
		self.processedPacketArray = []
		self.sendsInOrder = sendsInOrder
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

	def createPacketArray(self):
		tempIndex = 0
		while tempIndex < expectedNumberOfPackets:
			self.processedPacketArray.append(self.createWrappedPacket(tempIndex , self.getNextDataPacket(tempIndex)))
			tempIndex += 1

	def clientFunction(self):
		global forwardGoingIndex,backwardGoingIndex,clientSendingLock,clientReceivingLock,stillRunning
		# Create a UDP socket
		self.readInputFile()
		self.createPacketArray()
		
		target_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		local_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

		target_address = (self.targetAddress, self.port)
		local_address = (self.localAddress , self.port)

		print("Client is starting up")
		#target_sock.settimeout(0.1)
		local_sock.bind(local_address)
		local_sock.settimeout(0.1)

		while stillRunning : 
			try:
				with clientAccessLock:
					if forwardGoingIndex > backwardGoingIndex:
						stillRunning = False
						break
					#get sending time
				currentPacketArray = []
				if self.sendsInOrder :
					tempSequenceNumber = forwardGoingIndex
					beginningSequenceNumber = forwardGoingIndex
					while (tempSequenceNumber < expectedNumberOfPackets) and (tempSequenceNumber < (beginningSequenceNumber + WINDOW_SIZE)) :
						currentPacketArray.append(self.processedPacketArray[tempSequenceNumber])
						tempSequenceNumber += 1
						print("Created Packet with ",tempSequenceNumber)
				else:
					tempSequenceNumber = backwardGoingIndex
					beginningSequenceNumber = backwardGoingIndex
					while (tempSequenceNumber > 0) and (tempSequenceNumber > (beginningSequenceNumber - WINDOW_SIZE)) :
						currentPacketArray.append(self.processedPacketArray[tempSequenceNumber])
						tempSequenceNumber -= 1
						print("Created Packet with ",tempSequenceNumber)

				print ( '\nClient sends ')

				#send it to server
				print("Target address", target_address)
				for currentPacket in currentPacketArray:
					sent = target_sock.sendto(currentPacket, target_address)
				#wait for r3 ack
				print("Just before waiting for local_sock")
				receivedACKPacket, server = local_sock.recvfrom(1000) # timeout exception
				print("AFTER waiting for local_sock")
				if receivedACKPacket :
					print("Received ACK PACK")
					#receive ack from r3 , so it doesn't flood the network with packets
					if(self.checkForChecksum(receivedACKPacket)):
						sequenceNumber , data = self.separateACKPacket(receivedACKPacket)
						if(data.decode() == "ACK"):						
							#print("ACK received by s")
							print("Client Received ACK for sequence number ", sequenceNumber)
							with clientAccessLock:
								self.lastReceivedTime = time.time()
								if self.sendsInOrder:
									forwardGoingIndex = sequenceNumber
								else:
									backwardGoingIndex = sequenceNumber
								if forwardGoingIndex > backwardGoingIndex:
									print("FINISH IT Expected Sequences " + str(forwardGoingIndex) + "-" + str(backwardGoingIndex))
									stillRunning = False
									break
						#print ( '\nClient received "%s"' % data )
						#print ("\nRTT in ms is : ", difference*1000)

			except socket.timeout:
				with clientAccessLock:
					if time.time() - self.lastReceivedTime > TIME_OUT_LIMIT:
						break
					if forwardGoingIndex > backwardGoingIndex:
						print("ENDING " + str(forwardGoingIndex) + " " + str(backwardGoingIndex))
						stillRunning = False
						break
					else:
						print("Releasing Lock , continue after timeout")
						continue
		print ( 'Client closing socket')
		target_sock.close()
		local_sock.close()


if __name__ == "__main__":
	#Initialization or target information for our node
	os.system("sudo ntpdate -u pool.ntp.org")
	numberOfClientThreads = 2

	targetAddresses = ['10.10.1.2','10.10.2.1']
	localAddresses = ['10.10.1.1','10.10.2.2']
	targetPort = 12000
	sendsInOrder = [True,False]

	clientThreads = []
	
	for i in range(numberOfClientThreads):
		#Initializes server and client classes
		clientThreads.append(Client(targetAddresses[i],targetPort,localAddresses[i],sendsInOrder[i]))

	for i in range(numberOfClientThreads):
		#Runs server and client
		clientThreads[i].startClient()

	#main thread waits for client and server threads to finish
	for i in range(numberOfClientThreads):
		clientThreads[i].waitForClient()
	
