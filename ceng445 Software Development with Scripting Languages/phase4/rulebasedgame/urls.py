from django.urls import path
from . import views
app_name = 'rulebasedgame'

urlpatterns = [
    path('', views.index, name='index'),
    path('loadgames', views.loadgames, name='loadgames'),
    path('<str:gamename>', views.detail, name='detail'),
    path('<str:gamename>/ready', views.join, name='join'),
    path('<str:gamename>/<int:playerid>/start', views.ready, name='ready'),
    path('<str:gamename>/<int:playerid>/checkready', views.checkready, name='checkready'),
    path('<str:gamename>/<int:playerid>/turn', views.turn, name='turn'),
    path('<str:gamename>/<int:playerid>/refresh', views.refresh, name='refresh'),
]

