from django.shortcuts import render, get_object_or_404, redirect
from django.http import HttpResponse, HttpResponseRedirect
# Create your views here.
from json import load
import random


class Game():
	"""docstring for Game"""
	# Not sure!!
	allGames = []

	def __repr__(self):
		return self.dict["name"]

	def __init__(self, path):  # constructor
		fp = open(path, 'r', encoding='utf-8-sig')
		jsonToDict = load(fp)
		self.dict = jsonToDict
		self.players = []
		self.joinable = True
		self.started = False
		self.cycles = self.dict.get("cycles")
		self.cells = self.dict["cells"]
		self.currentTurn = None
		self.diceNumber = self.dict["dice"]
		self.nextTurn = None
		self.name = self.dict.get("name")
		self.allGames.append(self)
		self.gameOver = False
		self.winner = None
		self.gameTypeValue = None
		self.loser = None
		self.type = "roll"
		self.cards = self.dict["cards"]
		self.negeldi = None
		#  gametype = {round:n} cycled n times or = firstcollect
		if isinstance(self.dict["termination"], type(dict())):
			self.gameType = list(self.dict["termination"].keys())[0]
			self.gameTypeValue = list(self.dict["termination"].values())[0]
		else:
			self.gameType = self.dict["termination"]  # finish = last cell, first broke = ilk batan

	def join(self, player):  # Player id joins game
		# burada ilk oyuncunun hazir demesiyle oyuna baska kisi giremiyor.
		# if(not any(map(lambda x:x.isReady,self.players))):
		if self.joinable is True:
			if len(list(filter(lambda x: x.id == player.id, self.players))) == 0:
				self.players.append(player)
				player.joined = True
				player.credit = self.dict["credit"]
				player.joinedGame = self
				return True
			return "Id"
		return "Ready"

	def ready(self, player):
		"""Player sets its state ready to start the game.
			When all joined users so far ready game starts.
			When first player marks himself/herself ready,
			no more players can join the game"""
		if not player.isReady:
			player.isReady = True
			self.joinable = False
		if all(map(lambda x: x.isReady, self.players)):
			self.currentTurn = self.players[0]
			self.started = True

	def listgames(self):
		"""Static method for getting list of games (name,
			state) served by the server. Player may call
			the join() method on joinable games later."""
		return list(map(lambda x: (x.dict["name"], x.state()), self.allGames))

	def state(self):
		"""Return full game state, the players position,
			cell descriptions, next turn etc."""
		playersPos = list(map(lambda x: {x: x.position}, self.players))
		playerRound = list(map(lambda x: {x: x.cycle}, self.players))
		playerCredit = list(map(lambda x: {x: x.credit}, self.players))
		playerArt = list(map(lambda x: {x: x.pickedArt}, self.players))
		playerTurnType = list(map(lambda x: {x: x.type}, self.players))
		cells = self.dict["cells"]
		return {"playersPos": playersPos, "credits": playerCredit, "negeldi": self.negeldi, "pickedArtifact": playerArt,
				"playerTurnType": playerTurnType, "playerroundno": playerRound, "currentTurn": self.currentTurn,
				"nextTurn": self.nextTurn, "winner": self.winner, "loser": self.loser, "gameOver": self.gameOver, "players": self.players, "cells": self.cells}

	def next(self, player):
		"""Player calls this for rolling the dice, and
			drawing a card. Returns the state change for
			the user with its description"""
		# actions will be held in here
		# print(self.state())
		# in phase2 we will check it is draw card or roll
		if player.type == "roll":
			goto = self.roll()
			self.negeldi = goto
			goto = player.position + goto
			# player zar salliyor ona gore action gerceklesiyor.
			# o sayi kadar ileri gidiyor. cell sayisini gecme durumunda cycled degilse gitmiyor
			if goto < len(self.cells):
				player.position = goto
			elif goto >= len(self.cells) and self.cycles != "False":
				player.cycle = player.cycle + 1
				player.position = goto - len(self.cells)
				if isinstance(self.cycles, type(int)):
					player.credit = player.credit + self.cycles

			for cell in self.cells:
				if cell["cellno"] == player.position:
					# action key var mi yok mu control ediliyor
					if "action" in cell.keys():
						if cell["action"] == "drawcard":

							player.type = "drawcard"
							break
						elif list(cell["action"].keys())[0] == "jump":
							self.jump(player, cell["action"]["jump"])
							break
						elif list(cell["action"].keys())[0] == "skip":
							self.skip(player, cell["action"]["skip"])
							break
						elif list(cell["action"].keys())[0] == "drop":
							self.drop(player, cell["action"]["drop"])
							break
						elif list(cell["action"].keys())[0] == "add":
							self.add(player, cell["action"]["add"])
							break
						elif list(cell["action"].keys())[0] == "pay":
							userid = int(cell["action"]["pay"].split(",")[0][1:])
							value = int(cell["action"]["pay"].split(",")[1][:-1])
							# todo: if payed player is out of the game. then we check this.

							userList = list(filter(lambda x: x.id == userid, self.players))
							if len(userList) != 0:
								user = userList[0]
								self.pay(player, user, value)
							else:
								self.drop(player, value)
							#
							break
					# todo: eger artifact bulunan cell'e baska bir aksiyonla gelinmisse type'i choice yap. aksiyon fonksiyonlarının icinde yapilicak.
					# choice yapinca artifact eklenmeden gidiyor turn'e
					elif "artifact" in cell.keys():

						player.type = "choice"
						player.artifacts.append(cell["artifact"])
				##todo: burada nasıl player'a ulasacaksın?
				# buralari dene implement etmeden once.


		# is it drawcard suddenly or in the next stage? If suddenly draw, then we should call turn function inside next.
		# yok eger hemen cekmiyorsa ve breakleyip oyuncunun turn'une gidecek typeı belirleyip
		# bos donuyorsa cok bi sey degistirmeye gerek yok.
		# basa if conditionlar koyup cellde ne var ne yok kontrol et.
		# ben hemen gerceklestirmedigi durumu impelement etmeyi dusunuyorum.
		# drawcard gelince bi sonraki tura geciyo. ayni sekilde artifact de oyle.
		# bir kez card çekiyor. hareketli bi şey gelmezse veya
		# gelse bile artık type roll'a donuyo ki surekli bulundugu yerde kalıp card çekmesin.
		elif player.type == "drawcard":
			choice = random.choice(self.cards)
			self.negeldi = choice
			if list(choice["action"].keys())[0] == "jump":
				self.jump(player, choice["action"]["jump"])
			# self.type = "roll"
			# player.type = "roll"
			elif list(choice["action"].keys())[0] == "skip":
				self.skip(player, choice["action"]["skip"])

				player.type = "roll"
			elif list(choice["action"].keys())[0] == "drop":
				self.drop(player, choice["action"]["drop"])

				player.type = "roll"
			elif list(choice["action"].keys())[0] == "add":
				self.add(player, choice["action"]["add"])

				player.type = "roll"
			elif list(choice["action"].keys())[0] == "pay":
				userid = int(choice["action"]["pay"].split(",")[0][1:])
				value = int(choice["action"]["pay"].split(",")[1][:-1])
				userList = list(filter(lambda x: x.id == userid, self.players))
				if len(userList) != 0:
					user = userList[0]
					self.pay(player, user, value)
				else:
					self.drop(player, value)
				player.type = "roll"

		# burada yanlis olan sey oyuncunun tipi olmali. oyunun type i degil. yoksa baska oyuncular sacma seyler yapacak.

		if self.gameType == "firstbroke":
			if player.credit < 0:
				self.loser = player
				self.gameOver = True
				maxCredit = max(p.credit for p in self.players)
				self.winner = list(filter(lambda x: x.credit == maxCredit, self.players))
		elif self.gameType == "finish":
			if player.position == len(self.cells) - 1:
				self.gameOver = True
				self.winner = player
		elif self.gameType == "round":
			if player.cycle == self.gameTypeValue:
				self.gameOver = True
				self.winner = player
		##TODO: condition for artifact picking
		elif self.gameType == "firstcollect":
			if player.pickedArt == self.gameTypeValue:
				self.gameOver = True
				self.winner = player
		if len(self.players) == 0:
			self.players = True
		# print(self.state())
		# print("\n")
		return self.state()

	def pay(self, first, last, value):
		if first.credit >= value:
			first.credit = first.credit - value
			last.credit = last.credit + value
		elif first.credit < value:
			last.credit = last.credit + first.credit
			first.credit = first.credit - value
			self.players.remove(first)

	def add(self, player, value):
		player.credit = player.credit + value

	def drop(self, player, value):
		player.credit = player.credit - value
		if player.credit < 0:
			self.players.remove(player)

	def skip(self, player, turns):
		player.hasToWait = turns

	def jump(self, player, position):
		if isinstance(position, type(str())):
			position = int(position.strip("="))
			player.position = position
		else:
			move = player.position + position
			if move > len(self.cells) and self.cycles != "False":  # cycle ise
				player.cycle = player.cycle + 1
				player.position = move - len(self.cells)
			elif move > len(
					self.cells) and self.cycles == "False":  # eger cycle degilse ve var olan cell sayisini asiyorsa hareket etme
				pass
			else:
				player.position = move
		# todo: after action taken, check the current cell what type is.
		for cell in self.cells:
			if cell["cellno"] == player.position:
				if "action" in cell.keys():
					if cell["action"] == "drawcard":
						player.type = "drawcard"
					else:
						player.type = "roll"
				elif "artifact" in cell.keys():
					player.type = "choice"
					player.artifacts.append(cell["artifact"])
				else:
					player.type = "roll"
				break

	def pick(self, player, pickbool):

		"""Player calls this for responding a pick choice."""
		# todo
		# artifact i nasıl transfer edecegine bak. burayi dictionary ile implement edebilirsin
		# pickten sonra tekrar player.type ı rolle cevir ayni yerde kalmasin
		if pickbool == True:
			artifactCell = list(filter(lambda x: x["cellno"] == player.position, self.cells))[0]
			# artifact silinmisse diger kisinin tipi roll oluyo.
			# ayni turda ayni celle gelmislerse orada artifact varsa birisi daha once almissa digerinin typeı roll oluyo. Dezavantajlı bi durum

			try:
				if artifactCell["artifact"] == player.artifacts[-1]:
					if player.credit >= player.artifacts[-1]["price"] and player.artifacts[-1]["price"] >= 0:
						player.credit -= player.artifacts[-1]["price"]

						player.pickedArt += 1
						currentArt = player.artifacts[-1]

						if currentArt["owned"] == "True":
							player.ownedArt.append(currentArt)
							pass
						else:
							# artifactCell = filter(lambda x: x["cellno"] == player.position, self.cells)
							for cell in self.cells:
								if cell["cellno"] == player.position:
									# todo: player.position degisiyor burada. yanlis. artifactin oldugu yeri silmiyo. dogru da olabilir su an.
									# todo: artifact siliniyor. ama o celle gelmis baska biri daha varsa onun artifact yok olmasi lazim.
									print("artifact silindi")
									del cell["artifact"]
							player.artifacts.remove(player.artifacts[-1])  # todo: if player is not owner delete the artifact which come here.
						# del artifactCell["artifact"]
						if "action" in currentArt.keys():
							action = list(currentArt["action"].keys())[0]
							if action == "jump":
								self.jump(player, currentArt["action"]["jump"])
							# self.type = "roll"
							# player.type = "roll"
							elif action == "skip":
								self.skip(player, currentArt["action"]["skip"])

								player.type = "roll"
							elif action == "drop":
								self.drop(player, currentArt["action"]["drop"])

								player.type = "roll"
							elif action == "add":
								self.add(player, currentArt["action"]["add"])

								player.type = "roll"
							elif action == "pay":
								userid = int(currentArt["action"]["pay"].split(",")[0][1:])
								value = int(currentArt["action"]["pay"].split(",")[1][:-1])
								user = list(filter(lambda x: x.id == userid, self.players))[0]
								self.pay(player, user, value)
								player.type = "roll"
						player.type = "roll"
						# end of taken actions

						# if not owned artifact will disappeari otherwise artifact user owns.

						# gameover conditions
						if self.gameType == "firstbroke":
							if player.credit < 0:
								self.loser = player
								self.gameOver = True
								maxCredit = max(p.credit for p in self.players)
								self.winner = list(filter(lambda x: x.credit == maxCredit, self.players))
						elif self.gameType == "finish":
							if player.position == len(self.cells) - 1:
								self.gameOver = True
								self.winner = player
						elif self.gameType == "round":
							if player.cycle == self.gameTypeValue:
								self.gameOver = True
								self.winner = player
						elif self.gameType == "firstcollect":
							if player.pickedArt == self.gameTypeValue:
								self.gameOver = True
								self.winner = player
						if len(self.players) == 0:
							self.gameOver = True
					# pickbool true and it dont have money then playertype roll

					else:
						player.type = "roll"
			except:
				player.type = "roll"
		else:
			player.type = "roll"

		return self.state()

	def roll(self):
		return random.randrange(1, self.diceNumber)


class Player():
	"""docstring for Player"""

	def __repr__(self):
		return self.nickname

	def __init__(self, id, nickname):
		"""Constructor; create a player for new user"""
		self.id = id
		self.nickname = nickname
		self.isReady = False
		self.joined = False
		self.joinedGame = None
		self.position = 0
		self.credit = None
		self.firstTurn = True
		self.state = None
		self.hasToWait = 0
		self.cycle = 0  # round icin
		self.turnNumber = 0  # skip icin
		self.type = "roll"
		self.artifacts = []  ##todo: artifacts what type should be?
		self.pickedArt = 0
		self.ownedArt = []


game1 = Game("deneme.json")
game2 = Game("deneme1.json")
game3 = Game("deneme2.json")
game4 = Game("deneme3.json")
game5 = Game("deneme4.json")
game6 = Game("deneme5.json")
game7 = Game("deneme6.json")
games = [game1, game2, game3, game4,game5,game6, game7]


# tum oyunlarin siralanacagi yer
def index(request):
	context = {'games': games}
	return render(request, 'rulebasedgame/index.html', context)


# her oyunun kendi sayfasi(details gibi)
def detail(request, gamename):
	data = request.POST
	# playerName= data.get("playername")
	context = {"name": gamename}
	return render(request, 'rulebasedgame/detail.html', context)


def join(request, gamename):
	data = request.POST
	playerName = data.get("playername")
	playerId = data.get("playerid")
	player = Player(int(playerId), playerName)
	if len(list(filter(lambda x: x.name == gamename, games)))== 0:
		context = {'games': games}
		return render(request, 'rulebasedgame/index.html', context) 
	game = list(filter(lambda x: x.name == gamename, games))[0]

	joined = game.join(player)

	if joined == "Id":
		context = {"name": gamename, 'cantJoinDueId': True}
		return render(request, 'rulebasedgame/detail.html', context)
	elif joined == "Ready":
		context = {'games': games, 'cantJoinDueReady': True}
		return render(request, 'rulebasedgame/index.html', context)
	else:
		context = {"name": game.name, "playername": playerName, "playerid": playerId, "players": game.players}
		return render(request, 'rulebasedgame/join.html', context)


def ready(request, gamename, playerid):
	game = list(filter(lambda x: x.name == gamename, games))[0]
	print(game.players, game.players[0].id)
	# player join olmadan girmeye calisiyo.
	player = list(filter(lambda x: x.id == int(playerid), game.players))[0]
	print("player id : ", player)
	if len(game.players) != 1:
		game.ready(player)
	else:
		 context = game.state()
		 context["currentTurn"] = game.currentTurn
		 context["playerid"] = playerid
		 context["playername"] = player.nickname
		 context["name"] = gamename
		 context["otherPlayersWaited"] = True
		 return render(request, 'rulebasedgame/ready.html', context)
	#context = {"playerid": playerid, "currentTurn": game.currentTurn, "players": game.players, "name": gamename}
	context = game.state()
	context["currentTurn"] = game.currentTurn
	context["playerid"] = playerid
	context["playername"] = player.nickname
	context["name"] = gamename
	if game.started:
		return render(request, 'rulebasedgame/turn.html', context)
	return render(request, 'rulebasedgame/ready.html', context)


def checkready(request, gamename, playerid):
	game = list(filter(lambda x: x.name == gamename, games))[0]
	player = list(filter(lambda x: x.id == int(playerid), game.players))[0]
	#context = {"playerid": playerid, "currentTurn": game.currentTurn, "players": game.players, "name": gamename}
	context = game.state()
	context["playername"] = player.nickname
	context["currentTurn"] = game.currentTurn
	context["playerid"] = playerid
	context["name"] = gamename
	if game.started:
		return render(request, 'rulebasedgame/turn.html', context)
	return render(request, 'rulebasedgame/ready.html', context)


# return HttpResponseRedirect("")

def turn(request, gamename, playerid):
	# game.players 0 ise game duracak
	# index hatasi alabiliriz bunu yapmadik daha
	game = list(filter(lambda x: x.name == gamename, games))[0]
	if len(game.players) == 1:
		context = game.state()
		context["gameOver"] = True
		context["winner"] = game.players[0]
		return render(request, 'rulebasedgame/turn.html', context)
	# oyuncu yok olmussa index'e gonderiyo
	if len(list(filter(lambda x: x.id == int(playerid), game.players))) == 0:
		context = game.state()
		context["gameisoverforplayer"] = True
		context["currentTurn"] = game.currentTurn
		context["name"] = gamename
		context["playerid"] = playerid
		return render(request, 'rulebasedgame/turn.html', context)

	player = list(filter(lambda x: x.id == int(playerid), game.players))[0]
	# oyun gameover olmus mu veya kazanan var mi kontrol gerek

	try:
		oldplayerIndex = game.players.index(player)
	except ValueError:
		# todo: oyuncunun yok olmasini da dusun !!!!!!!!!!!!!!!!!
		context = {'games': games}
		return render(request, 'rulebasedgame/index.html', context)
		
		# todo: oyuncunun yok olmasini da dusun !!!!!!!!!!!!!!!!! dusundum sanirim direkt indexe yolluyo
		# yaptim: todo: skipte patliyoruz !!!!!!!!!!!! artik patlamiyoruz. 
		# sadece turne basmasi skipte olsa bile gerekiyor. 
		# yapmadim: bunu if hastowait ile değiştirebiliriz. onun sonuna al game.currentturnu
		# yaptim: hastoWaiti de yazdır ekrana ve yine turne bassın
		# todo: pick gelince turn'e if' le pick the arficact falan yazdir.
		# todo: drawcarda daha fazla card ekle ve cardlari sil. bu durumda oyuncuya drawcard gelirse ve card yoksa zar attir.
		# todo: gameover olunca oyunları sifirla
		# yaptim: todo: oyuncu sayisi 1 ise basamasin. oyuncu sayisini kontrol et.

	# turn dogru siradaki oyuncudan mi gelmis kontrol
	if player.id == game.currentTurn.id:

		player.turnNumber = player.turnNumber + 1
		# nextleri cagir
		# burasi player classinin aynisi olacak
		# dusunmemiz gereken sey oyun nasil ilerleyecek?
		if player.hasToWait == 0:
			if player.type == "roll":
				context = game.next(player)
			# game.currentTurn = game.players[playerIndex+1]
			elif player.type == "drawcard":
				context = game.next(player)
			# game.currentTurn = game.players[playerIndex+1]
			elif player.type == "choice":
				choice = request.POST['pick']
				if choice == "true" or choice == "True":
					context = game.pick(player, True)
				# game.currentTurn = game.players[playerIndex+1]
				else:
					context = game.pick(player, False)
				# game.currentTurn = game.players[playerIndex+1]
		else:
			player.hasToWait = player.hasToWait - 1
			context = game.state()
		# game.currentTurn = game.players[playerIndex+1]
		# oyuncu sayisini kontrol ediyoruz
		# todo: birisi elenince ilk oyuncuya gidiyor sira
		# parasi bittigi icin elenirse tekrar oyuncuyu ariyor. varsa index zaten ayni. yoksa eski oyuncunun indexini kullaniyoruz.
		try:
			playerIndex = game.players.index(player)
			if playerIndex + 1 >= len(game.players):
				game.currentTurn = game.players[0]
			else:
				if game.gameOver == False:
					 game.currentTurn = game.players[playerIndex + 1]
		# oyuncu elendi, sira devam ediyor.
		except ValueError:
			if oldplayerIndex >= len(game.players):	#degisti
				game.currentTurn = game.players[0]
			else:
				if game.gameOver == False:
					 game.currentTurn = game.players[oldplayerIndex] #degisti



	else:
		context = game.state()

	context["currentTurn"] = game.currentTurn
	context["playerid"] = playerid
	context["playerType"] = player.type
	context["playername"] = player.nickname
	context["name"] = gamename
	context["hasToWait"] = player.hasToWait
	# context = {"playerid": playerid, "currentTurn": game.currentTurn, "players": game.players, "name": gamename}
	return render(request, 'rulebasedgame/turn.html', context)


def refresh(request, gamename, playerid):
	game = list(filter(lambda x: x.name == gamename, games))[0]
	if len(list(filter(lambda x: x.id == int(playerid), game.players))) == 0:
		
		context =game.state()
		context["gameisoverforplayer"] = True
		context["currentTurn"] = game.currentTurn
		context["playerid"] = playerid
		context["name"] = gamename
		return render(request, 'rulebasedgame/turn.html', context)

	player = list(filter(lambda x: x.id == int(playerid), game.players))[0]
	context = game.state()

	context["playerid"] = playerid
	context["playerType"] = player.type
	context["playername"] = player.nickname
	context["name"] = gamename
	context["hasToWait"] = player.hasToWait

	return render(request, 'rulebasedgame/turn.html', context)
