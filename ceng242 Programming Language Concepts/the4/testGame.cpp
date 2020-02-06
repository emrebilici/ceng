#include"Game.h"
#include"InputParser.h"
#include<iostream>


int main(){

  Game *game = InputParser::parseGame();
  //Game *game = new Game(5,4,Coordinate(1,2));
  //Player *archer = new Archer(0,1,4,BARBARIANS);
  //game->addPlayer(0,0,0,BARBARIANS, "ARCHER");
  //game->addPlayer(3,0,1,BARBARIANS, "SCOUT");
  //game->addPlayer(2,0,2,BARBARIANS, "SCOUT");
  //game->addPlayer(1,0,3,KNIGHTS, "FIGHTER");
  //game->addPlayer(5,1,3,KNIGHTS, "PRIEST");
  //game->addPlayer(4,3,3,BARBARIANS, "PRIEST");

  Board *board = game->getBoard();
  std::cout << "Board with CLASS" << std::endl;
  board->printBoardwithClass();
  std::cout << "Board with ID" << std::endl;
  board->printBoardwithID();
//  game->isGameEnded();
  
  while(!game->isGameEnded()){
    game->playTurn();
    board->printBoardwithClass();
    std::cout << "--------------" << std::endl;
    board->printBoardwithID();


  }


}
