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

serverAccessLock = Lock()

inOrderReceivedData = []
backwardOrderReceivedData = []

totalData = []

forwardGoingIndex = 0
backwardGoingIndex = 5555
receivedBefore = False
stillRunning = True


class Server():
	def __init__(self,address,port,repeaterAddress,inOrderReceiver):
		#Initializations(ex. socket, etc.)
		self.address = address
		self.port = port
		self.repeaterAddress = repeaterAddress
		self.receivedCounter = 0
		self.sendTimes = []
		self.receiveTimes = []
		self.firstReceivalTime = None
		self.lastReceivalTime = None
		self.inOrderReceiver = inOrderReceiver

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

		serverThread = Thread(target = self.serverFunction )
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
		global serverAccessLock,inOrderReceivedData,backwardOrderReceivedData,forwardGoingIndex,backwardGoingIndex,receivedBefore,stillRunning
		receiving_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		repeating_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

		# Bind the socket to the port
		server_address = (self.address, self.port)
		repeater_address = (self.repeaterAddress , self.port)
		print ('Server is starting up on %s port %s' % server_address)


		receiving_sock.settimeout(0.1)
		receiving_sock.bind(server_address)

		while stillRunning:
			#print ('\n Server waits to receive message')
			try:
				receivedPacket, address = receiving_sock.recvfrom(1000)
				if receivedPacket:
					if(self.checkForChecksum(receivedPacket)):
						sequenceNumber , dataLength , sendingTime,  data = self.separateDataPacket(receivedPacket)
						with serverAccessLock:
							if(receivedBefore == False):
								self.receivedBefore = True
								self.firstReceivalTime = sendingTime
							self.lastReceivalTime = time.time()
							if stillRunning == False:
								break
							if forwardGoingIndex > backwardGoingIndex:
								stillRunning = False
								break
							if self.inOrderReceiver:
								if(sequenceNumber == forwardGoingIndex):
									print("Sequence number matches for forward ",forwardGoingIndex)
									inOrderReceivedData.append(data)
									sendingPacket = self.createResponsePacket(forwardGoingIndex)
									forwardGoingIndex += 1
									sendACK = repeating_sock.sendto(sendingPacket,repeater_address)
							else:
								if(sequenceNumber == backwardGoingIndex):
									print("Sequence number matches for backward ",backwardGoingIndex)
									backwardOrderReceivedData.append(data)
									sendingPacket = self.createResponsePacket(backwardGoingIndex)
									backwardGoingIndex -= 1
									sendACK = repeating_sock.sendto(sendingPacket,repeater_address)

			except socket.timeout:
				with serverAccessLock:
					if stillRunning == False:
						break
					if(receivedBefore == False):
						continue
					if(forwardGoingIndex > backwardGoingIndex):
						stillRunning = False
						break
					if self.inOrderReceiver:
						sendingPacket = self.createResponsePacket(forwardGoingIndex)
						print("Timeout occured , forward expected sequence number ",forwardGoingIndex)
					else:
						sendingPacket = self.createResponsePacket(backwardGoingIndex)
						print("Timeout occured , backward expected sequence number ",backwardGoingIndex)
					sendACK = repeating_sock.sendto(sendingPacket,repeater_address)
		with serverAccessLock:
			totalTransferTime = self.lastReceivalTime - self.firstReceivalTime
		print("Total TransferTime is : ", totalTransferTime)
		print ( 'Server closing socket')
		receiving_sock.close()
		repeating_sock.close()

if __name__ == "__main__":
	#Initialization or target information for our node
	os.system("sudo ntpdate -u pool.ntp.org")
	#TODO CHECK DOWNED LINKS 
	localAddresses = ['10.10.4.2','10.10.5.2']
	repeaterAddresses = ['10.10.4.1','10.10.5.1']
	localPort = 12000
	numberOfServerThreads = 2
	inOrderSenders = [True,False]

	serverThreads = []

	for i in range(numberOfServerThreads):
		#Initializes server and client classes
		serverThreads.append(Server(localAddresses[i],localPort,repeaterAddresses[i],inOrderSenders[i]))

	for i in range(numberOfServerThreads):
		#Runs server and client
		serverThreads[i].startServer()

		#main thread waits for client and server threads to finish
	for i in range(numberOfServerThreads):
		serverThreads[i].waitForServer()
	with open("receivedFile.txt","wb") as outputFile :
		print("Forward index + backwards index : "+ str(forwardGoingIndex) + str(backwardGoingIndex))
		counter = 0
		for data in inOrderReceivedData:
			outputFile.write(data)
			counter+=1
		print("Counter for forwards data is :")
		for data in reversed(backwardOrderReceivedData):
			if counter > expectedNumberOfPackets:
				break
			outputFile.write(data)
			counter+=1