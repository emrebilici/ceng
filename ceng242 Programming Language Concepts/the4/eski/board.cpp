#include "Board.h"
#include <vector>
#include <iostream>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/


Board::Board(uint boardSize, std::vector<Player *> *players):boardSize(boardSize), players(players), width(0){
  //std::cout <<"constructora girdim" << std::endl;
}

Board::~Board(){

}


uint Board::getSize() const{
  return boardSize;
}

bool Board::isCoordInBoard(const Coordinate& coord) const{

  Coordinate bs = Coordinate(boardSize-1, boardSize-1);
  Coordinate nbs = Coordinate(0, 0);

  if((coord.operator<(bs) || coord.operator==(bs)) && (nbs.operator<(coord) || nbs.operator==(coord))){
    return true;
  }
  return false;

}

bool Board::isStormInCoord(const Coordinate &coord) const{

  if(!isCoordInBoard(coord)){
    return false;
  }

  if(isCoordHill(coord)){
    return false;
  }

  if(isNotinStorm(coord) == false){
    return true;
  }
  return false;


}

bool Board::isNotinStorm(const Coordinate &coord) const{
/*
  Coordinate far = Coordinate(boardSize-width-1, boardSize-width-1);
  Coordinate near = Coordinate(width, width);
  if((coord.operator<(far) || coord.operator==(far)) && (near.operator<(coord) || near.operator==(coord))){
    return true;
  }
  return false;*/

  for(int i=width; i<=boardSize-width-1; i++){
    for(int j=width; j<=boardSize-width-1; j++){
      if(coord == Coordinate(i,j)){
        return true;
      }
    }
  }
}

bool Board::isCoordHill(const Coordinate& coord) const{

  if(boardSize % 2 == 1){
      int mid = (boardSize -1) / 2;
      Coordinate middle = Coordinate(mid, mid);
      if(coord == middle){
        return true;
      }
  }
  return false;

}

Player *Board::operator[](const Coordinate& coord) const{

  if(!isCoordInBoard(coord)){
    return nullptr;
  }
  for(int i = 0; i<players->size(); i++){
    if((*players)[i]->getCoord() == coord){
      return (*players)[i];
    }
  }
  return nullptr;

}

Coordinate Board::calculateCoordWithMove(Move move, const Coordinate &coord) const{

  if(move == ATTACK || move == NOOP){
    return coord;
  }

  Coordinate newcoord = coord.operator+(move);

  if(!isCoordInBoard(newcoord)){
    return coord;
  }
  if(operator[](newcoord) != nullptr){
    return coord;
  }

  return newcoord;

}

std::vector<Coordinate> Board::visibleCoordsFromCoord(const Coordinate &coord) const{

  std::vector<Coordinate> voc;

  if(!isCoordInBoard(coord)){
    return voc;
  }

  Coordinate up_coord = coord.operator+(UP);
  Coordinate down_coord = coord.operator+(DOWN);
  Coordinate left_coord = coord.operator+(LEFT);
  Coordinate right_coord = coord.operator+(RIGHT);

  if(isCoordInBoard(up_coord)){
    voc.push_back(up_coord);
  }
  if(isCoordInBoard(down_coord)){
    voc.push_back(down_coord);
  }
  if(isCoordInBoard(left_coord)){
    voc.push_back(left_coord);
  }
  if(isCoordInBoard(right_coord)){
    voc.push_back(right_coord);
  }

  return voc;

}

void Board::updateStorm(uint currentRound){

  this->width = Entity::stormWidthForRound(currentRound);

}

std::vector<Player *> * Board::getVector() const{
  return players;
}

Coordinate Board::getHill() const{
  if(boardSize % 2 == 1){
      int mid = (boardSize -1) / 2;
      Coordinate middle = Coordinate(mid, mid);
      return middle;
  }


}


//ilkya

#include "Board.h"
#include <iostream>
#include <algorithm>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Board::Board(uint boardSize, std::vector<Player *> *players): boardSize(boardSize), players(players) {}
Board::~Board(){}

uint Board::getSize() const {
  return this->boardSize;
}

Player* Board::getPlayer(int id) const {
  int i = 0;
  while (i < players->size()) {
    if (id == players->at(i)->getID())
      return players->at(i);
    i++;
  }
  return nullptr;
}

std::vector<Player*>* Board::getPlayersVector() const {
  return this->players;
}

void Board::removePlayer(uint id) {
  int i = 0;
  while (i < players->size()) {
    if (id == players->at(i)->getID()) {
      players->erase(std::remove(players->begin(), players->end(), players->at(i)), players->end());
    }
    i++;
  }
}


bool Board::isCoordInBoard(const Coordinate& coord) const {
  for(uint y = 0; y < boardSize; y++) {
    for (uint x = 0; x < boardSize; x++) {
      if (x == coord.x && y == coord.y)
        return true;
      }
    }
  return false;
}
/**
 * Decide whether the given coordinate is in storm.
 *
 * @param coord Coordinate to search.
 * @return true if covered in storm, false otherwise.
 */
bool Board::isStormInCoord(const Coordinate &coord) const {
  if (isCoordHill(coord) || !isCoordInBoard(coord))
    return false;
  if (std::find(stormZoneCoords.begin(), stormZoneCoords.end(), coord) != stormZoneCoords.end())
    return true;

}

bool Board::isCoordHill(const Coordinate& coord) const {
  if (this->boardSize % 2 == 1) {
    int i = (boardSize - 1) / 2;
    if (coord.x == i && coord.y == i)
      return true;
  }
  return false;
}

Player* Board::operator[](const Coordinate& coord) const {
  if (!isCoordInBoard(coord)) return nullptr;
  int i = 0;
  while (i < players->size()) {
    if (players->at(i)) {
      if (coord == players->at(i)->getCoord())
        return players->at(i);
      }
    i++;
  }
  return nullptr;
/*
  std::vector<Player*> &vr = *players;
  while (i < players->size()) {
    if (coord == vr[i]->getCoor()) {
      std::cout << vr[i] << std::endl;
      return vr[i];
    }
    i++;
  }
  return nullptr;
  */
}

/**
 * Also, if there's another player in the new coordinate,
 * return coord.
 */
Coordinate Board::calculateCoordWithMove(Move move, const Coordinate &coord) const {
  int newX, newY;
  newX = coord.x;
  newY = coord.y;
  switch (move) {
    case UP:
      newY -= 1;
      break;
    case DOWN:
      newY += 1;
      break;
    case LEFT:
      newX -= 1;
      break;
    case RIGHT:
      newX += 1;
      break;
    default:
      return coord;
  }
  Coordinate newCoord(newX, newY);
  if (!isCoordInBoard(newCoord))
    return coord;

  int i = 0;
  while (i < players->size()) {
    if (players->at(i)) {
      if (newCoord == players->at(i)->getCoord())
        return coord;
      }
    i++;
  }
  return newCoord;
}

std::vector<Coordinate> Board::visibleCoordsFromCoord(const Coordinate &coord) const {
  std::vector <Coordinate> v;
  if (isCoordInBoard(coord)) {
    if (isCoordInBoard(coord.operator+(UP)))
      v.push_back(coord.operator+(UP));
    if (isCoordInBoard(coord.operator+(DOWN)))
      v.push_back(coord.operator+(DOWN));
    if (isCoordInBoard(coord.operator+(LEFT)))
      v.push_back(coord.operator+(LEFT));
    if (isCoordInBoard(coord.operator+(RIGHT)))
      v.push_back(coord.operator+(RIGHT));
  }
  return v;
}


/**
 * Calculate the storm according to the currentRound.
 *
 * @param currentRound The current round being played.
 */
void Board::updateStorm(uint currentRound) {
  if ((currentRound - 1) % 5 != 0) return;
  uint stormWidth = Entity::stormWidthForRound(currentRound);
  int smallestX = stormWidth - 1;
  int smallestY = stormWidth - 1;
  int greatestX = this->boardSize - stormWidth;
  int greatestY = this->boardSize - stormWidth;

  this->stormZoneCoords.push_back(Coordinate(smallestX, smallestY));

  int i = smallestX + 1;
  while (i <= greatestX) {
    this->stormZoneCoords.push_back(Coordinate(i, smallestY));
    this->stormZoneCoords.push_back(Coordinate(smallestY, i));
    i++;
  }

  this->stormZoneCoords.push_back(Coordinate(greatestX, greatestY));

  int j = greatestY - 1;
  while(j >= smallestY) {
    this->stormZoneCoords.push_back(Coordinate(greatestX, j));
    this->stormZoneCoords.push_back(Coordinate(j, greatestX));
    j--;
  }
}