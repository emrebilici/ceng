import game,socket,pickle, client

class Player():
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
        self.type = "roll"
        self.artifacts = []	 ##todo: artifacts what type should be?
        self.pickedArt = 0
        self.ownedArt = []

    def join(self, game1):
        """calls game.join(self) if user is no in a game"""

        game1.join(self)
        if self.joined:
            self.joinedGame = game1
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
        print("turn for: {0}".format(self))
        self.turnNumber = self.turnNumber + 1
        if self.hasToWait == 0:
            if type == "roll":
                self.type = "roll"
                self.joinedGame.next(self)
            elif type == "drawcard":
                self.type = "drawcard"
                self.joinedGame.next(self)
            elif type == "choice":
                self.type = "choice"
                #inputlu

                # input server terminal'den alınıyor ancak #todo:
                # choice = input("True or False to pick artifact. Your credit is {0} and artifact price is {1}".format(self.credit, self.artifacts[-1]["price"]))
                # if choice == "True":
                #     self.joinedGame.pick(self, True)
                # else:
                #     self.joinedGame.pick(self, False)

                # inputsuz hali asagida
                if self.credit >= self.artifacts[-1]["price"] and self.artifacts[-1]["price"]>=0:
                    self.credit -= self.artifacts[-1]["price"]
                    self.joinedGame.pick(self,True)
                else:
                    self.joinedGame.pick(self,False)
        else:
            print("{0} skip".format(self))
            self.hasToWait = self.hasToWait - 1


    def notify(self):

        pass
    # We will exacute the each test one by one
    """Each two lines show the initial state before player plays and final state after player played."""