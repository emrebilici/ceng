""" We assume that if the player rolls the dice. It forward as much as dice number.
 and if there is an action on that cell it do not wait, it suddenly play that action.
  If there is no action on that cell it will wait its turn. 
  In finish game, if dice number is bigger than last cell, it wont action.
  """
import game
import player

def main():
    # test1()
    # test2()
    # test3()
    # test4()
    #test5()
    # test6()
    # test7()
    # test8()
    test9()

def test1():
    """This will try to add player after one player is ready"""
    #deneme1,deneme
    print("-------------Test1-------------\n")
    game1 = game.game.Game("deneme1.json")
    game2 = game.game.Game("deneme.json")
    player1 = player.player.Player(1, "emre")
    player2 = player.player.Player(2, "mustafa")
    player3 = player.player.Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player1.ready()
    player3.join(game1)
    if player1 in game1.players and player2 in game1.players and player3 not in game1.players:
        print("test1 is passed. {0} and {1} are players of this game.".format(player1,player2))
    if game1.winner == None:
        return "There is no winner since all of them lost their money."

    if game1 in game1.allGames and game2 in game1.allGames:
        print("All games is added to server: {0} and {1}".format(game1,game2))
        print("Listgames function:")
        print(game1.listgames())

def test2():
    """This is round game."""
    #deneme
    print("-------------Test2-------------\n")
    game1 = game.Game("deneme.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player1.ready()
    player3.join(game1)
    player3.ready()
    player2.ready()

    print("Round game. round no: 3 ")
    if player1 in game1.players and player2 in game1.players and player3 not in game1.players:
        print("joined players are true")
    if game1.winner == None:
        return "There is no winner since all of them lost their money."
    if game1.winner.cycle == game1.gameTypeValue:
        print("For test2: player {0} is winner reaching the desiring round number {1} ".format(game1.winner, game1.gameTypeValue))


def test3():
    """This is finish game with 3 player"""
    """If player's position is not changed. It do not move. So state will not change until dice number small enough."""
    #deneme1
    print("-------------Test3-------------\n")
    game1 = game.Game("deneme1.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
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
    if game1.winner == None:
        return "There is no winner since all of them lost their money."

    if game1.winner.position == game1.cells[-1]["cellno"]:
        print("For test3: player {0} is winner reaching the last cell {1} ".format(game1.winner, game1.cells[-1]["cellno"]))


def test4():
    """This is firstbroke game with cycles"""
    #deneme2
    print("-------------Test4-------------\n")
    game1 = game.Game("deneme2.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player3.join(game1)
    player1.ready()
    player3.ready()
    player2.ready()
    print("Firstbroke game. There is cycle.")
    if player1 in game1.players and player2 in game1.players and player3 in game1.players:
        print("joined players are true")
    if game1.winner == None:
        return "There is no winner since all of them lost their money."

    if game1.winner is not None:
        for w in game1.winner:
            print("For test4: player {0} is winner and its credit is {1}".format(w, w.credit))
    print("For test4: player {0} is loser".format(game1.loser))


def test5():
    #deneme3
    print("-------------Test5-------------\n")
    print("This is firstbroke game and 4 player. deneme3.json is used")
    game1 = game.Game("deneme3.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
    player4 = player.Player(4, "dorduncu murat")
    player5 = player.Player(5, "yok daha neler")
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
    if game1.winner == None:
        return "There is no winner since all of them lost their money."

    if game1.winner is not None:
        for w in game1.winner:
            print("For test5: player {0} is winner and its credit is {1}".format(w,w.credit))


def test6():
    """This is round game."""
    #deneme4
    print("-------------Test6-------------\n")
    game1 = game.Game("deneme4.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    player1.ready()
    player3.join(game1)
    player3.ready()
    player2.ready()
    print("Round game. round no: 5 ")
    if player1 in game1.players and player2 in game1.players and player3 not in game1.players:
        print("joined players are true")
    if game1.winner == None:
        return "There is no winner since all of them lost their money."
    if game1.winner.cycle == game1.gameTypeValue:
        print("For test6: player {0} is winner reaching the desiring round number {1} ".format(game1.winner, game1.gameTypeValue))

def test7():
    """This is finish game."""
    #deneme5
    print("-------------Test7-------------\n")
    game1 = game.Game("deneme5.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
    player1.join(game1)
    player2.join(game1)
    if player1 in game1.players and player2 in game1.players and player3 not in game1.players:
        print("joined players are true")
    player1.ready()
    player2.ready()
    print("Finish game. cell 20 ")
    if game1.winner == None:
        return "There is no winner since all of them lost their money."
    if game1.winner.position == game1.cells[-1]["cellno"]:
        print("For test7: player {0} is winner reaching the last cell {1} ".format(game1.winner, game1.cells[-1]["cellno"]))

def test8():
    print("-------------Test8-------------\n")
    game1 = game.Game("deneme4.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
    player4 = player.Player(4, "dorduncu")
    player1.join(game1)
    player2.join(game1)
    player3.join(game1)
    player4.join(game1)
    if player1 in game1.players and player2 in game1.players and player3 in game1.players and player4 in game1.players:
        print("joined players are true")
    player1.ready()
    player3.ready()
    player2.ready()
    player4.ready()
    print("Round game. round no: 5. There are 4 players ")

    if game1.winner == None:
        return "There is no winner since all of them lost their money."
    if game1.winner.cycle == game1.gameTypeValue:
        print("For test8: player {0} is winner reaching the desiring round number {1} ".format(game1.winner, game1.gameTypeValue))

def test9():
    print("-------------Test8-------------\n")
    game1 = game.Game("deneme6.json")
    player1 = player.Player(1, "emre")
    player2 = player.Player(2, "mustafa")
    player3 = player.Player(3, "gereksiz")
    player4 = player.Player(4, "dorduncu")
    player1.join(game1)
    player2.join(game1)
    player3.join(game1)
    player4.join(game1)
    if player1 in game1.players and player2 in game1.players and player3 in game1.players and player4 in game1.players:
        print("joined players are true")

    player1.ready()
    player3.ready()
    player2.ready()
    player4.ready()
    print("firstcollect game. collect no: 5. There are 3 players ")

    if game1.winner == None:
        return "There is no winner since all of them lost their money."
    if game1.winner.pickedArt == game1.gameTypeValue:
        print("For test8: player {0} is winner reaching the desiring artifact number {1} ".format(game1.winner, game1.gameTypeValue))
    if game1.winner:
        print("For test8: player {0} is winner but it did not reach the desiring arifact number {1}".format(game1.winner, game1.gameTypeValue))

if __name__ == '__main__':
    main()



# todo: artifact false check this situation.