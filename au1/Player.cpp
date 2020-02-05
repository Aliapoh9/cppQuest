#include "Player.hpp"
#include <iostream>

const double P_SCALE = 1;

Player::Player(int lv, int exp, double c) : Character("Genijiro", 200, 350, 100), Level(lv), Experience(exp), Currency(c)
{
    initSprite();
    Character::setAccelY(9.81);
    Character::setTerminalVel(500);
}


void Player::initSprite()
{
    Character::setSpriteR(15, 0, 16, 40);
    Character::setTexture("Assets/Sprites/Knight/knight_idle.png", P_SCALE, 0);
}


void Player::updateAnimation()
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
        case 1:
        {
            int r1 = Character::getSpriteRect().left;
            if (r1 == 0)
                r1 = 15;
            Character::setSpriteR(r1, 0, 16, 40);
            Character::setTexture("Assets/Sprites/Knight/knight_walk.png", P_SCALE, 0);

            if (r1 > 42 * 6)
                r1 = 15;
            else
                r1 += 42;
            Character::setSpriteR(r1, 0, 16, 40);
            break;
        }
        case 2:
        {
            int r1 = Character::getSpriteRect().left;
            if (r1 == 0)
                r1 = 15;
            Character::setSpriteR(r1, 0, 16, 40);
            Character::setTexture("Assets/Sprites/Knight/knight_walk.png", P_SCALE, 0);
            Character::invertSprite();

            if (r1 > 42 * 6)
                r1 = 15;
            else
                r1 += 42;
            Character::setSpriteR(r1, 0, 16, 40);
            break;
        }
        case 3:
        {
            int r1 = Character::getSpriteRect().left;
            if (!(r1 % 8 == 0))
                r1 = 0;
            Character::setSpriteR(r1, 39, 49, 40);
            Character::setTexture("Assets/Sprites/Knight/knight_attack.png", P_SCALE, 0);
           // std::cout << Character::getSpriteRect().left << std::endl;
            if (r1 > 80 * 8)
            {
                Character::setSpriteR(0, 39, 49, 40);
                Character::setState(0);
                break;
            }
            else
                r1 += 80;
            Character::setSpriteR(r1, 39, 49, 40);
            break;
        }
        case 4:
        {
            int ogPosX = Character::getSprite().getPosition().x;
            Character::move(5, 0);

        }
        default:
            break;
    }

}

void Player::move(float offX, float offY)
{
    Character::move(offX, offY);
}

void Player::setJumping(bool jump)
{
    Jumping = jump;
}

void Player::setExp(int Exp)
{
    Experience = Exp;
}

void Player::setLevel(int Lvl)
{
    Level = Lvl;
}

void Player::setCurrency(double G)
{
    Currency = G;
}
