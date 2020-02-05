#include "Mercenary.hpp"

#include <iostream>

const double P_SCALE = 3;

Mercenary::Mercenary() : PartyMember("Mercenary", 80, 24)
{
    initSprite();
}


void Mercenary::initSprite()
{
    Character::setSpriteR(200, 0, 30, 50);
    Character::setTexture("Assets/Sprites/Mercenary/HB.png", P_SCALE, 0);
    Character::invertSprite();
}


void Mercenary::updateAnimation()
{
    switch (Character::getState())
    {
        case 0:
        {
            int r1 = Character::getSpriteRect().left;
            Character::setSpriteR(r1, 0, 30, 50);
            if (r1 > 200 + 42 * 3)
                r1 = 200;
            else
                
                r1 += 48;
            Character::setSpriteR(r1, 0, 30, 50);
            break;
        }
        case 1:
        {
            int r1 = Character::getSpriteRect().left;
            Character::setSpriteR(r1, 0, 16, 40);
            
            if (r1 > 42 * 6)
                r1 = 15;
            else
                r1 += 42;
            Character::setSpriteR(r1, 0, 16, 40);
            break;
        }

        case 3:
        {

        }
        default:
            break;
    }
    
}
