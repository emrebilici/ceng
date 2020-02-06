#include "Player.h"
#include <string>
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Player::Player(uint id, int x, int y): coordinate(x, y), id(id) {}
Player::~Player() {}

uint Player::getID() const {
  return this->id;
}
const Coordinate& Player::getCoord() const {
  return this->coordinate;
}

int Player::getHP() const {
  return this->HP;
}

std::string Player::getBoardID() const {
  if (this->id < 10) {
    std::string unitsDigit = std::to_string(this->id);
    std::string boardID = "0" + unitsDigit;
    return boardID;
  }
  else {
    std::string boardID = std::to_string(this->id);
    return boardID;
  }
}

Armor Player::getArmor() const {
  return this->getArmor();
}

Weapon Player::getWeapon() const {
  return this->getWeapon();
}

std::vector<Move> Player::getPriorityList() const {
  return this->getPriorityList();
}

const std::string Player::getFullName() const {
  return this->getFullName();
}

const std::string Player::getName() const {
  return this->getName();
}


bool Player::isDead() const {
  return (this->HP <= 0);
}
//"Tracer00(100) moved UP."
void Player::executeMove(Move move) {
    std::string moveStr;
    switch (move) {
      case UP:
        moveStr = "UP";
        break;
      case DOWN:
        moveStr = "DOWN";
        break;
      case LEFT:
        moveStr = "LEFT";
        break;
      case RIGHT:
        moveStr = "RIGHT";
        break;
      default:
        moveStr = "noop";
    }

    if (moveStr != "noop") {
      this->coordinate = this->coordinate.operator+(move);
      std::cout << this->getFullName() << "(" << this->getHP() << ") moved " << moveStr << "." << std::endl;
    }
}

// "Tracer00(100) ATTACKED Tracer01(100)! (-10)"
bool Player::attackTo(Player *player) {
  if (!player->isDead() && player != this) {
    int lhsDamage = Entity::damageForWeapon(this->getWeapon());
    int rhsArmor = Entity::damageReductionForArmor(player->getArmor());
    int playerOldHP = player->getHP();
    player->HP -= std::max((lhsDamage - rhsArmor), 0);
    int damageDone = player->getHP() - playerOldHP;
    if (damageDone == 0) std::cout << this->getFullName() << "(" << this->getHP() << ") ATTACKED " << player->getFullName() << "(" << playerOldHP << ")! (-" << damageDone << ")" << std::endl;
    else
      std::cout << this->getFullName() << "(" << this->getHP() << ") ATTACKED " << player->getFullName() << "(" << playerOldHP << ")! (" << damageDone << ")" << std::endl;
  }
  return (player->isDead());
}

void Player::setHPAfterStorm(int damage) {
  this->HP -= damage;
}

bool compare(const Player &lhs, const Player &rhs) {
  return lhs.getID() < rhs.getID();
}


/**
 * Return different colors for different Player classes (override!).
 *
 * Note: This method is optional. You may leave this as-is.
 *
 * @return The associated color code with the class.
 */
 /*
Color::Code Player::getColorID() const {
  return this->getColorID();
}
*/




// BA14


#include "Player.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Entity.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/


Player::Player(uint id, int x, int y):id(id), coordinate(x,y), HP(100){}

Player::~Player(){

}

uint Player::getID() const{
  return id;
}

const Coordinate& Player::getCoord() const{
  return coordinate;
}

int Player::getHP() const{
  return HP;
}

std::string Player::getBoardID() const{

  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << id;
  std::string s = ss.str();

  return s;

}

bool Player::isDead() const{
  if(HP <= 0){
    return true;
  }
  return false;
}

void Player::executeMove(Move move){ /*MIGHT NEED TO HANDLE MORE CASES*/

  coordinate = coordinate.operator+(move);


  if(move == UP){
    std::cout << getFullName();
    std::cout << "(";
    std::cout << getHP();
    std::cout << ") moved ";
    std::cout << "UP" << std::endl;
  }
  else if(move == DOWN){
    std::cout << getFullName();
    std::cout << "(";
    std::cout << getHP();
    std::cout << ") moved ";
    std::cout << "DOWN" << std::endl;
  }
  else if(move == RIGHT){
    std::cout << getFullName();
    std::cout << "(";
    std::cout << getHP();
    std::cout << ") moved ";
    std::cout << "RIGHT" << std::endl;
  }
  else if(move == LEFT){
    std::cout << getFullName();
    std::cout << "(";
    std::cout << getHP();
    std::cout << ") moved ";
    std::cout << "LEFT" << std::endl;
  }

}

bool Player::attackTo(Player *player){ /*check what damage is*/
  if(this != player){

    int damagedone = std::max((Entity::damageForWeapon(this->getWeapon()) - Entity::damageReductionForArmor(player->getArmor())), 0);

    std::cout << this->getFullName();
    std::cout << "(";
    std::cout << this->getHP();
    std::cout << ") attacked ";
    std::cout << player->getFullName();
    std::cout << "(";
    std::cout << player->getHP();
    std::cout << ")! (-";
    std::cout << damagedone;
    std::cout << ")" << std::endl;

    player->HP -= damagedone;


    if(player->HP <=0){
      return true;
    }
    return false;
  }
}

void Player::setHP(int n){
  HP = n;
}

bool Player::sortID(const Player* lhs, const Player* rhs) const { return lhs->getID() < rhs->getID(); }


//kaaaan
#include "Player.h"
#include <iostream>
#include <string>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/


Player::Player(uint id, int x, int y) : id(id), coordinate(x,y) {

}

std::string Player::getBoardID() const {
	std::string res;
	if(id < 10)
		res = "0" + std::to_string(id);
	else
		res = std::to_string(id);
	return res;
}

void Player::setHP(int x){
	HP = x;
}
uint Player::getID() const {
	//std::cout << this << std::endl;
	return id;
}

int Player::getHP() const {
	return HP;
}

bool Player::isDead() const {
	return (HP <= 0);
}

const Coordinate& Player::getCoord() const {
	return coordinate;
}

Player::~Player() {
	;
}


void Player::executeMove(Move move) {

	if(move != NOOP or move != ATTACK){
		Coordinate new_coordinate = coordinate + move;
		coordinate = new_coordinate;
		if(move == UP)
		std::cout << getFullName() << "(" << getHP() << ")" << "moved UP." << std::endl;
		if(move == DOWN)
		std::cout << getFullName() << "(" << getHP() << ")" << "moved DOWN." << std::endl;
		if(move == LEFT)
		std::cout << getFullName() << "(" << getHP() << ")" << "moved LEFT." << std::endl;
		if(move == RIGHT)
		std::cout << getFullName() << "(" << getHP() << ")" << "moved RIGHT." << std::endl;
	}
}

bool Player::attackTo(Player *player) {
	if(this == player)
		return false;
	int damage_done = Entity::damageForWeapon(this -> getWeapon());
	int damage_absorb = Entity::damageReductionForArmor(player -> getArmor());
	int damage_net = damage_done - damage_absorb;
	if(damage_net < 0 )
		damage_net = 0;
	player -> setHP( player -> getHP() - damage_net);
	std::cout << this -> getFullName() << "(" << this -> getHP() << ") attacked " << player -> getFullName() << "(" << player -> getHP() << ")! (-" << damage_net << ")" << std::endl;

	return (player -> isDead());
}


/*bool Player::operator<(const Player &rhs) const {
	return (this -> id < rhs.id);
}*/
