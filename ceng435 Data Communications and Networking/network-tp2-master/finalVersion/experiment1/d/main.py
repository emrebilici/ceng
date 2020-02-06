import time
import socket
import sys
from threading import Thread , Lock
import os
import struct

#Constants for file and packet size
SENDING_FILE_SIZE = 5000000
PACKET_SIZE = 900
expectedNumberOfPackets = (SENDING_FILE_SIZE // PACKET_SIZE) + 1

WINDOW_SIZE = 10
#locks for thread synchronization
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
		#seperates headers and data from packet
		sequenceNumber = struct.unpack("I", receivedPacket[2:6])[0]
		dataLength = struct.unpack("H",receivedPacket[6:8])[0]
		sendingTime = struct.unpack("d",receivedPacket[8:16])[0]
		data = receivedPacket[16:]
		return sequenceNumber , dataLength , sendingTime , data

	def checkForChecksum(self, receivedPacket):
		#unpacks checksum from header
		receivedChecksum = struct.unpack("H",receivedPacket[:2])[0] #this is due unpack returning a tuple
		#calculates checksum
		calculatedChecksum = self.calculateChecksum(receivedPacket[2:])
		#check if they match
		return receivedChecksum == calculatedChecksum

	def calculateChecksum(self,packetData):
		#self explanatory
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
		#wraps ack'ed sequence no and checksum into a packet
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
		sock.settimeout(0.1) # important for resends
		sock.bind(server_address)
		
		while stillRunning:
			try:
				with serverReceivingLock: #to make sure indices are kept safe
					receivedPacket, address = sock.recvfrom(1000)
					#upon packet receival
					if receivedPacket: 
						# if packet is not corrupted
						if(self.checkForChecksum(receivedPacket)): 
							#seperate the packet
							sequenceNumber , dataLength , sendingTime,  data = self.separateDataPacket(receivedPacket)
							if(sequenceNumber == self.expectedSequenceNumber):
								#if expected sequence no arrived
								if(sequenceNumber == 0):
									#keep the first packet arrival time
									self.firstReceivalTime = sendingTime
								#add it to data array
								self.receivedData.append(data)
								#update the latest arrival
								self.lastReceivalTime = time.time()
								#create ack for sequence no
								sendingPacket = self.createResponsePacket(self.expectedSequenceNumber)
								#send ack for received packet
								sendACK = sock.sendto(sendingPacket,address)

								#increase the expected sequence no
								self.expectedSequenceNumber += 1
			except socket.timeout:
				if(self.expectedSequenceNumber == 0):
					#on startup wait until a packet is received 
					continue
				sendingPacket = self.createResponsePacket(self.expectedSequenceNumber)
				sendACK = sock.sendto(sendingPacket,address)
				if(self.expectedSequenceNumber == expectedNumberOfPackets):
					#received all packets
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
