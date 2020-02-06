#include "Pacifist.h"
#include <sstream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
// Name     : Pacifist
// Priority : { UP, LEFT, DOWN, RIGHT }

// Armor    : METAL
// Weapon   : NOWEAPON
// HP       : 100

Pacifist::Pacifist(uint id, int x, int y): Player(id, x, y) {this->HP = 100;}

Armor Pacifist::getArmor() const {return METAL;}

Weapon Pacifist::getWeapon() const {return NOWEAPON;}

std::vector<Move> Pacifist::getPriorityList() const {return { UP, LEFT, DOWN, RIGHT }; }

const std::string Pacifist::getFullName() const {
  std::stringstream id;
  id << this->getBoardID();
  std::string fullName = "Pacifist" + id.str();
  return fullName;
}

const std::string Pacifist::getName() const {
  return "Pacifist";
}


Color::Code Pacifist::getColorID() const {return Color::FG_GREEN;}