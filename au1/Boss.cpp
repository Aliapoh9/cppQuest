//
//  Boss.cpp
//  au1
//
//  Created by Reynauld on 10/5/2562 BE.
//  Copyright © 2562 Reynauld. All rights reserved.
//

#include "Boss.hpp"

const double BOSS_SCALE = 1.25;

Boss::Boss() : Enemies("Uproar", 230, 700, 50, 1000, 1000)
{
    Character::setState(0);
    Character::setAccelY(9.81);
    Character::setTerminalVel(500);
    loadTextures();
    initSprite();
}

void Boss::loadTextures()
{
    sf::Image newImage;
    sf::Texture newTexture;
    newImage.loadFromFile(resourcePath() + "Assets/Sprites/Boss/Boss.png");
    newImage.createMaskFromColor(sf::Color(47, 72, 78));
    newTexture.loadFromImage(newImage);
    SpriteTextures.push_back(newTexture);
}

void Boss::initSprite()

{
    
    Character::setSpriteR(0, 0, 500, 500);
    Character::setTexture(SpriteTextures[0], BOSS_SCALE, 0);
    
}

void Boss::updateAnimation()
{
    switch (Character::getState()) {
        case 0:
        {
            int r1 = Character::getSpriteRect().left;
            Character::setSpriteR(50, 40, 100, 140);
            Character::setTexture(SpriteTextures[0], BOSS_SCALE, 0);
            Character::invertSprite();
            if (r1 > 204 * 2)
                r1 = 50;
            else
                
                r1 += 204;
            Character::setSpriteR(r1, 40, 100, 140);
            break;
        }
            
        default:
            break;
    }
    
}
