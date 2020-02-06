#include "Ambusher.h"


#include "Color.h"
#include "Coordinate.h"
#include "Entity.h"
#include <sstream>
#include <vector>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Ambusher::Ambusher(uint id, int x, int y):Player(id,x,y){}

Armor Ambusher::getArmor() const{
  return NOARMOR;
}

Weapon Ambusher::getWeapon() const{
  return SEMIAUTO;
}

std::vector<Move> Ambusher::getPriorityList() const{
  return { ATTACK };
}

const std::string Ambusher::getFullName() const{
  std::stringstream ss;
  ss << "Ambusher" << getBoardID();
  std::string s = ss.str();

  return s;
}

Color::Code Ambusher::getColorID() const{
  return Color::FG_BLUE;
}

