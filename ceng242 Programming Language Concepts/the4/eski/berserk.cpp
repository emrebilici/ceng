#include "Berserk.h"

#include "Color.h"
#include "Coordinate.h"
#include "Entity.h"
#include <sstream>
#include <vector>


/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Berserk::Berserk(uint id, int x, int y):Player(id,x,y){}

Armor Berserk::getArmor() const{
  return WOODEN;
}

Weapon Berserk::getWeapon() const{
  return PISTOL;
}

std::vector<Move> Berserk::getPriorityList() const{

  return { ATTACK, UP, LEFT, DOWN, RIGHT };
}

const std::string Berserk::getFullName() const{
  std::stringstream ss;
  ss << "Berserk" << getBoardID();
  std::string s = ss.str();

  return s;
}

Color::Code Berserk::getColorID() const{
  return Color::FG_RED;
}
