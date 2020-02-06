from django.shortcuts import render, redirect
from django.http import HttpResponse



# Create your views here.


gameChosen = False
current_game = None


def index(request):
    return HttpResponse("<h1>Hello World</h1>")


def game(request):
    games = [{"name": "game1"}, {"name": "game2"}]
    global current_game
    # global gameChosen
    # if gameChosen:
    #     return render(request, "gameEntered.html", {"current_game": current_game})
    return render(request, "game.html", {'games': games, 'current_game': current_game})


def choose(request):
    if request.GET["submit"] == "Choose":
        global current_game
        # global gameChosen
        # gameChosen = True
        current_game = request.GET["game"]
        print(request.GET["id"])
        return render(request, "gameEntered.html", {"current_game": current_game})


def refresh(request):
    return HttpResponse("<h2>Refresh</h2>")


def join(request):
    return HttpResponse("<h2>Join</h2>")


def ready(request):
    return HttpResponse("<h2>Ready</h2>")