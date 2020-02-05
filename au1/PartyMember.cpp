//
//  PartyMember.cpp
//  au1
//
//  Created by Reynauld on 8/5/2562 BE.
//  Copyright © 2562 Reynauld. All rights reserved.
//

#include "PartyMember.hpp"

PartyMember::PartyMember(std::string name, int mh, int d, int lvl, int exp) : Character(name, 100, mh, d), Level(lvl), Experience(exp) {}


void PartyMember::move(float offX, float offY)
{
    Character::move(offX, offY);
}

void PartyMember::setExp(int Exp)  // Also level the character up if possible.
{
    Experience = Exp;
    if (Exp >= ExpReq)
    {
        Level += 1;
        Character::setDamage(Character::getDamage() + 2);
        Character::setMaxHealth(Character::getMaxHealth() + 10);
        Character::setHealth(Character::getMaxHealth());
        ExpReq += (5 * Level);
        Experience = Experience - ExpReq;
    }
}

void PartyMember::setLevel(int Lvl)
{
    Level = Lvl;
}
