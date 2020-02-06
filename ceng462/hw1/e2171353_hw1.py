import copy
#python3 ile calistirin
class Node(object):
	"""docstring for Node."""
	def __init__(self, data,level,parent):
		super(Node, self).__init__()
		self.data = data
		self.level = level
		self.fvalue = None
		self.parent = parent
		#self.goal = goal
		#self.successors = []
	def __repr__(self):
		return "<< Node-> data: " + str(self.data) + ", level: " + str(self.level)  + ", fvalue: " +str(self.fvalue) +  ">>"
	# returns a Node list which is successors
	def produce_succ(self):
		level = self.level
		data = self.data
		successors =[]
		size = len(data)
		location = ()
		i=0
		j=0
		for i in range(len(data)):
			for j in range(len(data[i])):
				if(data[i][j]=='_'):
					location = (i,j)
					break
			if (len(location)==2):
				break
		right = j + 1
		left = j - 1
		up = i - 1
		down = i + 1
		#moving = {right,left,down, up}
		temp = copy.deepcopy(data)
		if ( i > 0):#yukari
			temp[i][j], temp[up][j] = data[up][j], data[i][j]
			if(self.parent is None or temp != self.parent.data):
				s = Node(temp, level + 1, self )
				successors.append(s)
			temp = copy.deepcopy(data)
		if (i < size - 1): #j<size asagi in
			temp[i][j], temp[down][j] = data[down][j], data[i][j]
			if(self.parent is None or temp != self.parent.data):
				s = Node(temp, level + 1, self )
				successors.append(s)
			temp = copy.deepcopy(data)
		if (j > 0): #sola git
			temp[i][j], temp[i][left] = data[i][left], data[i][j]
			if(self.parent is None or temp != self.parent.data):
				s = Node(temp, level + 1, self )
				successors.append(s)
			temp = copy.deepcopy(data)
		if (j < size - 1): #j<size saga git
			temp[i][j], temp[i][right] = data[i][right], data[i][j]
			if(self.parent is None or temp != self.parent.data):
				s = Node(temp, level + 1, self )
				successors.append(s)
			temp = copy.deepcopy(data)



		return successors



class Asearch(object):
	"""docstring for Asearch."""
	def __init__(self, initial ,goal, maxR):
		super(Asearch, self).__init__()
		self.initial = initial
		self.goal = goal
		self.open = []
		self.close = []
		self.maxR = maxR
	#return a minimum fvalue node
	def findMinF(self,openList):
		if(len(openList)==1):
			return openList[0]
		else:
			min = openList[0]
			for node in openList:
				if (node.fvalue < min.fvalue):
					min = node
		return min

	def isThereLowerF(self, node, closeList):
		if(len(closeList)==0):
			return False
		else:
			for i in closeList:
				if(node.data == i.data and i.fvalue <= node.fvalue):
					return True
			return False

	def hValue(self,node,goal):
		hValue = 0
		for i in range(len(node.data)):
			for j in range(len(node.data)):
				if node.data[i][j] != '_':
					hValue += abs(i - self.findGoalIndex(node.data[i][j],goal)[0]) + abs(j - self.findGoalIndex(node.data[i][j],goal)[1])
		return hValue

	def findGoalIndex(self,no,goal):
		for i in range(len(goal.data)):
			try:
				return (i,goal.data[i].index(no))
			except ValueError:
				pass

	def search(self):
		self.open.append(self.initial)
		self.initial.fvalue = self.hValue(self.initial,self.goal)
		while (len(self.open)):
			q = self.findMinF(self.open)
			self.open.remove(q)
			if(q.fvalue > self.maxR -1):
				return None
			if(q.data == self.goal.data):

				self.goal.parent = q.parent;
				return q

			elif (self.isThereLowerF(q,self.close)==False):
				successors = q.produce_succ()
				willaddsucc = []

				for s in successors:
					s.fvalue = s.level + self.hValue(s,self.goal)
					if s not in self.open:
						willaddsucc.append(s)
					# for i in self.open:
					# 	if(s.data != i.data):
					# 		willaddsucc.append(s)
					# 		break
					# not in seklinde YAZABILIRDIN!! KONTROL
					# for j in self.close:
					# 	if(s.data == j.data):
					# 		willaddsucc.remove(s)
					# 		willaddsucc.append(j)
					# 		break
				self.close.append(q)

				self.open = self.open + willaddsucc
			#     #eger closed listte daha kucuk fvalue li bir node daha yoksa
			#     # node'u closed liste gonder, expand et. ve successors  open liste ekle.
			#     # bu biraz daha farkli geeksforgeeks'ten bence bunu dene once.
			#
		return None
# openlist empty ise return fail
# q = minimum fvaluelu olan node in openlist.
# if q.data == goal.data ise return q
# if (q.fvalue < self.findMinF(self.closed)[0].fvalue && q.data != self.findMinF(self.closed)[0].data )
# then self.closed.append(q)
# q.produce_succ(); openList + q.produce_succ()

class IDAsearch(object):
	def __init__(self, initial ,goal,maxR):
		super(IDAsearch, self).__init__()
		self.initial = initial
		self.goal = goal
		self.open = []
		self.close = []
		self.maxR = maxR

	def hValue(self,node,goal):
		hValue = 0
		for i in range(len(node.data)):
			for j in range(len(node.data)):
				if node.data[i][j] != '_':
					hValue += abs(i - self.findGoalIndex(node.data[i][j],goal)[0]) + abs(j - self.findGoalIndex(node.data[i][j],goal)[1])
		return hValue

	def findGoalIndex(self,no,goal):
		for i in range(len(goal.data)):
			try:
				return (i,goal.data[i].index(no))
			except ValueError:
				pass

	def limitedFSearch(self, lastNode, gvalue, fmax):
		#lastNode = -1
		fvalue = gvalue + self.hValue(lastNode, self.goal)
		if(fvalue > fmax):
			return (False,fvalue)
		if(self.goal.data==lastNode.data):
			return (True, lastNode)
		successors = lastNode.produce_succ()
		min = self.maxR
		for succ in successors:
			succ.fvalue = succ.level + self.hValue(succ,self.goal)
			#if succ not in
				#append(succ)
			t = self.limitedFSearch(succ, gvalue + 1, fmax )
			if (t[0]==True):
				return (True,t[1])
			if( t[1] < min):
				min = t[1]
				#pop()
		return (False,min)

	def search(self):
		fmax = self.hValue(self.initial,self.goal)
		while (True):
			res = self.limitedFSearch(self.initial,0,fmax)
			if(res[0]==True):
				return res[1]
			if(res[1]==self.maxR):
				return -1
			fmax = res[1]
		return -1

def printData(node):
	countcol = 0
	for i in range(len(node.data)):
		row = ""

		count = 0
		if(countcol==0):
			row = "\n"
		for j in range(len(node.data[i])):
			if(count == (len(node.data[i]) -1)):
				row += str(node.data[i][j])
			else:
				row += str(node.data[i][j]) + " "
			count = count + 1
		countcol = countcol +1
		print(row)

def getInput():
	firstThree = []
	for i in range(3):
		firstThree.append( input())
	maxR = int(firstThree[1])
	initial =[]
	line =[]
	for j in range(int(firstThree[2])):
		row = []
		line = input().split(" ")
		for k in line:
			if(k=='_'):
				row.append(k)
			else:
				row.append(int(k))
		initial.append(row)
	goal = []
	line =[]
	for j in range(int(firstThree[2])):
		row = []
		line = input().split(" ")
		for k in line:
			if(k=='_'):
				row.append(k)
			else:
				row.append(int(k))
		goal.append(row)

	node = Node(initial,0,None)
	goal = Node(goal,0,None)

	if(firstThree[0]=="A*"):
		a = Asearch(node,goal,maxR)
		b = a.search()
		if(b == None or b == -1):
			print( 'FAILURE')
		else:
			print ( 'SUCCESS')
			trackNode = b;
			nodeList = []
			while (trackNode != None):
				nodeList.append(trackNode)
				trackNode = trackNode.parent
			nodeList.reverse()
			for i in nodeList:
				printData(i)

	elif(firstThree[0]=="IDA*"):
		a = IDAsearch(node,goal,maxR)
		b = a.search()
		if(b == None or b == -1 or b ==maxR):
			print( 'FAILURE')
		else:
			print ( 'SUCCESS')
			trackNode = b
			nodeList = []
			while (trackNode != None):
				nodeList.append(trackNode)
				trackNode = trackNode.parent
			nodeList.reverse()
			for i in nodeList:
				printData(i)
	#[[1,2,3],[5,6,7],[8,4,"_"]]
	#[[1,2,3],[4,5,6],[7,"_",8]] --0
	#[[1,2,3],['_',4,6],[7,5,8]] --2 once bu
	#[[1,2,3],[7,4,6],['_',5,8]] --1    sonra bu bug oluyo
	#[['_',2,3],[7,1,6],[4,5,8]]
	#sorun string olarak gormesinden


getInput()
