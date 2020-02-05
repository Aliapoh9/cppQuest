//
//  Knight.cpp
//  au1
//
//  Created by Reynauld on 9/5/2562 BE.
//  Copyright © 2562 Reynauld. All rights reserved.
//

#include "Knight.hpp"
#include <iostream>

const double P_SCALE = 3;

Knight::Knight() : PartyMember("Knight", 120, 15)  //NAME, MAXHP, DAMAGE
{
    initSprite();
}


void Knight::initSprite()
{
    Character::setSpriteR(200, 0, 30, 50);
    Character::setTexture("Assets/Sprites/Knight/knight_idle.png", P_SCALE, 0);
    Character::invertSprite();
}


void Knight::updateAnimation()
{
    switch (Character::getState())
    {
        case 0:
        {
            int r1 = Character::getSpriteRect().left;
            if (r1 == 0)
                r1 = 15;
            Character::setSpriteR(r1, 0, 16, 40);
            Character::setTexture("Assets/Sprites/Knight/knight_idle.png", P_SCALE, 0);
            if (r1 > 42 * 2)
                r1 = 15;
            else
                
                r1 += 42;
            Character::setSpriteR(r1, 0, 16, 40);
            break;
        }
        default:
            break;
    }
    
}
