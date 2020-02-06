from json import load
import random

""" We assume that if the player rolls the dice. It forward as much as dice number.
 and if there is an action on that cell it do not wait, it suddenly play that action.
  If there is no action on that cell it will wait its turn. 
  In finish game, if dice number is bigger than last cell, it wont action.
  """
class Game:
    """docstring for Game"""
    # Not sure!!
    allGames = []
    def __repr__(self):
        return self.dict["name"]
    def __init__(self, path):  # constructor
        fp = open(path,'r',encoding='utf-8-sig')
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
        #self.name = self.dict.get("name")
        self.allGames.append(self)
        self.gameOver = False
        self.winner = None
        self.gameTypeValue = None
        self.loser = None
        #  gametype = {round:n} cycled n times or = firstcollect
        if isinstance(self.dict["termination"], type(dict())):
            self.gameType = list(self.dict["termination"].keys())[0]
            self.gameTypeValue = list(self.dict["termination"].values())[0]
        else:
            self.gameType = self.dict["termination"] #finish = last cell, first broke = ilk batan


    def join(self, player):  # Player id joins game
        #burada ilk oyuncunun hazir demesiyle oyuna baska kisi giremiyor.
        #if(not any(map(lambda x:x.isReady,self.players))):
        if self.joinable is True:
            self.players.append(player)
            player.joined = True
            player.credit = self.dict["credit"]
            player.joinedGame = self
        return

    def ready(self, player):
        """Player sets its state ready to start the game.
            When all joined users so far ready game starts.
            When first player marks himself/herself ready,
            no more players can join the game"""
        if not player.isReady:
            player.isReady = True
            self.joinable = False
        if all(map(lambda x:x.isReady,self.players)):
            self.nextTurn = self.players[0]
            self.started = True
            self.start()

    def listgames(self):
        """Static method for getting list of games (name,
            state) served by the server. Player may call
            the join() method on joinable games later."""
        return list(map(lambda x: (x.dict["name"], x.state()), self.allGames))

    def state(self):
        """Return full game state, the players position,
            cell descriptions, next turn etc."""
        playersPos = list(map(lambda x: {x: x.position}, self.players))
        playerRound = list(map(lambda x : {x: x.cycle}, self.players))
        playerCredit = list(map(lambda x : {x: x.credit}, self.players))
        cells = self.dict["cells"]
        return {"playersPos": playersPos, "credits": playerCredit ,"player round no": playerRound, "currentTurn": self.currentTurn ,"nextTurn" : self.nextTurn, "winner" : self.winner, "gameOver": self.gameOver}

    def next(self, player):
        """Player calls this for rolling the dice, and
            drawing a card. Returns the state change for
            the user with its description"""
        # actions will be held in here
        # print(self.state())
        # in phase2 we will check it is draw card or roll
        goto = self.roll()
        goto = player.position + goto
        # player zar salliyor ona gore action gerceklesiyor. o sayi kadar ileri gidiyor. cell sayisini gecme durumunda cycled degilse gitmiyor
        if goto < len(self.cells):
            player.position = goto
        elif goto >= len(self.cells) and self.cycles != "False":
            player.cycle = player.cycle + 1
            player.position = goto - len(self.cells)
            if isinstance(self.cycles, type(int)):
                player.credit = player.credit + self.cycles

        # buraya bak. finish oldugunda hareket etmemesi lazim = burasinin da tamam olmasi lazım cycles false ise zaten gitmiyor.
        # cycles olmadiginda hareket etmemesi lazim= burasi tamam
        for cell in self.cells:
            if cell["cellno"] == player.position:
                # action key var mi yok mu control ediliyor
                if len(list(cell.items())) > 2:
                    if list(cell["action"].keys())[0] == "jump":
                        self.jump(player, cell["action"]["jump"] )
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
                        user = list(filter(lambda x: x.id == userid, self.players))[0]
                        self.pay(player, user, value)
                        break
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
        # print(self.state())
        # print("\n")
        return self.state()

    def start(self):
        i = 0
        while i < len(self.players):
            self.currentTurn = self.players[i]
            if self.winner and self.gameOver:
                break
            elif i == len(self.players) - 1:
                self.nextTurn = self.players[0]
                self.players[i].turn("roll")
                i = -1
            else:
                self.nextTurn = self.players[i+1]
                self.players[i].turn("roll")
            i = i+ 1

    def pay(self,first, last, value):
        if first.credit >= value:
            first.credit = first.credit - value
            last.credit = last.credit + value
        elif first.credit < value:
            first.credit = first.credit - value
            last.credit = last.credit + first.credit

    def add(self, player, value):
        player.credit = player.credit + value

    def drop(self,player, value):
        player.credit = player.credit - value

    def skip(self,player, turns):
        player.hasToWait = turns

    def jump(self, player, position):
        if isinstance(position, type(str())):
            position = int(position.strip("="))
            player.position = position
        else:
            move = player.position + position
            if move > len(self.cells) and self.cycles != "False":  #cycle ise
                player.cycle = player.cycle + 1
                player.position = move - len(self.cells)
            elif move > len(self.cells) and self.cycles == "False":  #eger cycle degilse ve var olan cell sayisini asiyorsa hareket etme
                pass
            else:
                player.position = move


    def pick(self, player, pickbool):
        """Player calls this for responding a pick choice."""
        pass

    def roll(self):
        return random.randrange(1, self.diceNumber)

class Player(Game):
    """docstring for Player"""
    def __repr__(self):
        return self.nickname

    def __init__(self, id,nickname):
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
        self.turnNumber = 0     # skip icin

    def join(self,game):
        """calls game.join(self) if user is no in a game"""
        game.join(self)
        if self.joined:
            self.joinedGame = game
        #    self.position = list(filter(lambda x:x["description"]=="Start",game.dict["cells"]))[0] ##

    def ready(self):
        """calls game.ready(self)"""
        if self.joined:
            self.joinedGame.ready(self)

    def turn(self,type):
        """notification method when next turn belongs
            to the player. type is roll at first notification.
            Player responds with a next() call. If type is
            drawcard, user responds again with a next()
            call. If it is choice with artifact description,
            user responds with a pick(self, True) or
            pick(self, False)"""
        # print("turn for: {0}".format(self))
        self.turnNumber = self.turnNumber + 1
        if self.hasToWait == 0:
            if type == "roll":
                self.joinedGame.next(self)
            else:
                pass
        else:
            # print("{0} skip".format(self))
            self.hasToWait = self.hasToWait - 1


    # We will exacute the each test one by one
    """Each two lines show the initial state before player plays and final state after player played."""
def main():
    test1()
    test2()
    test3()
    test4()
    test5()
    test6()
    test7()
    test8()


def test1():
    """This will try to add player after one player is ready"""
    #deneme1,deneme
    print("-------------Test1-------------\n")
    game1 = Game("deneme1.json")
    game2 = Game("deneme.json")
    player1 = Player(1, "emre")
    player2 = Player(2, "mustafa")
    player3 = Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player1.ready()
    player3.join(game1)
    if player1 in game1.players and player2 in game1.players and player3 not in game1.players:
        print("test1 is passed. {0} and {1} are players of this game.".format(player1,player2))
    if game1 in game1.allGames and game2 in game1.allGames:
        print("All games is added to server: {0} and {1}".format(game1,game2))
        print("Listgames function:")
        print(game1.listgames())

def test2():
    """This is round game."""
    #deneme
    print("-------------Test2-------------\n")
    game1 = Game("deneme.json")
    player1 = Player(1, "emre")
    player2 = Player(2, "mustafa")
    player3 = Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player1.ready()
    player3.join(game1)
    player3.ready()
    player2.ready()

    print("Round game. round no: 3 ")
    if player1 in game1.players and player2 in game1.players and player3 not in game1.players:
        print("joined players are true")
    if game1.winner.cycle == game1.gameTypeValue:
        print("For test2: player {0} is winner reaching the desiring round number {1} ".format(game1.winner, game1.gameTypeValue))


def test3():
    """This is finish game with 3 player"""
    """If player's position is not changed. It do not move. So state will not change until dice number small enough."""
    #deneme1
    print("-------------Test3-------------\n")
    game1 = Game("deneme1.json")
    player1 = Player(1, "emre")
    player2 = Player(2, "mustafa")
    player3 = Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player3.join(game1)
    player1.ready()
    player3.ready()
    player2.ready()
    print("Finish game. No cycle.")
    print("If player's position is not changed.It doesnt move.So state will not change until dice number small enough.")
    if player1 in game1.players and player2 in game1.players and player3 in game1.players:
        print("joined players are true")
    if game1.winner.position == game1.cells[-1]["cellno"]:
        print("For test3: player {0} is winner reaching the last cell {1} ".format(game1.winner, game1.cells[-1]["cellno"]))


def test4():
    """This is firstbroke game with cycles"""
    #deneme2
    print("-------------Test4-------------\n")
    game1 = Game("deneme2.json")
    player1 = Player(1, "emre")
    player2 = Player(2, "mustafa")
    player3 = Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player3.join(game1)
    player1.ready()
    player3.ready()
    player2.ready()
    print("Firstbroke game. There is cycle.")
    if player1 in game1.players and player2 in game1.players and player3 in game1.players:
        print("joined players are true")
    if game1.winner is not None:
        for w in game1.winner:
            print("For test4: player {0} is winner and its credit is {1}".format(w, w.credit))
    print("For test4: player {0} is loser".format(game1.loser))


def test5():
    """This is firstbroke game and 4 player"""
    #deneme3
    print("-------------Test5-------------\n")
    game1 = Game("deneme3.json")
    player1 = Player(1, "emre")
    player2 = Player(2, "mustafa")
    player3 = Player(3, "gereksiz")
    player4 = Player(4, "dorduncu murat")
    player5 = Player(5, "yok daha neler")
    player1.join(game1)
    player2.join(game1)
    player3.join(game1)
    player4.join(game1)
    player1.ready()
    player5.join(game1)
    player3.ready()
    player2.ready()
    player4.ready()

    print("Firstbroke game. 4 player")
    print("For test5: player {0} is loser".format(game1.loser))
    if player1 in game1.players and player2 in game1.players and player3 in game1.players and player4 in game1.players and player5 not in game1.players:
        print("joined players are true")
    if game1.winner is not None:
        for w in game1.winner:
            print("For test5: player {0} is winner and its credit is {1}".format(w,w.credit))


def test6():
    """This is round game."""
    #deneme4
    print("-------------Test6-------------\n")
    game1 = Game("deneme4.json")
    player1 = Player(1, "emre")
    player2 = Player(2, "mustafa")
    player3 = Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player1.ready()
    player3.join(game1)
    player3.ready()
    player2.ready()
    print("Round game. round no: 5 ")
    if player1 in game1.players and player2 in game1.players and player3 not in game1.players:
        print("joined players are true")
    if game1.winner.cycle == game1.gameTypeValue:
        print("For test6: player {0} is winner reaching the desiring round number {1} ".format(game1.winner, game1.gameTypeValue))

def test7():
    """This is finish game."""
    #deneme5
    print("-------------Test7-------------\n")
    game1 = Game("deneme5.json")
    player1 = Player(1, "emre")
    player2 = Player(2, "mustafa")
    player3 = Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player1.ready()
    player2.ready()
    print("Finish game. cell 20 ")
    if player1 in game1.players and player2 in game1.players and player3 not in game1.players:
        print("joined players are true")
    if game1.winner.position == game1.cells[-1]["cellno"]:
        print("For test7: player {0} is winner reaching the last cell {1} ".format(game1.winner, game1.cells[-1]["cellno"]))

def test8():
    print("-------------Test8-------------\n")
    game1 = Game("deneme4.json")
    player1 = Player(1, "emre")
    player2 = Player(2, "mustafa")
    player3 = Player(3, "gereksiz")
    player4 = Player(4, "dorduncu")
    player1.join(game1)
    player2.join(game1)
    player3.join(game1)
    player4.join(game1)
    player1.ready()
    player3.ready()
    player2.ready()
    player4.ready()
    print("Round game. round no: 5. There are 4 players ")
    if player1 in game1.players and player2 in game1.players and player3 in game1.players and player4 in game1.players:
        print("joined players are true")
    if game1.winner.cycle == game1.gameTypeValue:
        print("For test8: player {0} is winner reaching the desiring round number {1} ".format(game1.winner, game1.gameTypeValue))


if __name__ == '__main__':
    main()