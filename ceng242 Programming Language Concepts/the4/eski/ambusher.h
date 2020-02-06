#ifndef HW4_AMBUSHER_H
#define HW4_AMBUSHER_H

#include "Color.h"
#include "Coordinate.h"
#include "Entity.h"

#include <vector>
#include "Player.h"

class Ambusher : public Player {
public:
    Ambusher(uint id, int x, int y);

    // Name     : Ambusher
    // Priority : { ATTACK }

    // Armor    : NOARMOR
    // Weapon   : SEMIAUTO
    // HP       : 100

    // DO NOT MODIFY THE UPPER PART
    // ADD OWN PUBLIC METHODS/PROPERTIES/OVERRIDES BELOW
/*
    const std::string a_name;
    std::vector<Move> a_plist;
    Armor a_armor;
    Weapon a_weapon;*/


    Armor getArmor() const override;

    Weapon getWeapon() const override;

    std::vector<Move> getPriorityList() const override;

    const std::string getFullName() const override;

    Color::Code getColorID() const override;
};


#endif //HW4_AMBUSHER_H
