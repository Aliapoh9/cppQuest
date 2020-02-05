
#include "Dark_Knight.hpp"

const double P_SCALE = 3;

DarkKnight::DarkKnight() : PartyMember("Dark Knight", 100, 20)  //NAME, MAXHP, DAMAGE
{
    initSprite();
}


void DarkKnight::initSprite()
{
    Character::setSpriteR(200, 0, 30, 50);
    Character::setTexture("Assets/Sprites/Knight/knight_idle.png", P_SCALE, 0);
    Character::invertSprite();
}


void DarkKnight::updateAnimation()
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
            Character::setColor(sf::Color::Black);
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
