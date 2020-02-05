#include "Goblin.hpp"

const double GOBLIN_SCALE = 0.20;

Goblin::Goblin() : Enemies("Goblin", 230, 100, 13, 200, 3)
{
    Character::setState(0);
    Character::setAccelY(9.81);
    Character::setTerminalVel(500);
    loadTextures();
    initSprite();
}

void Goblin::loadTextures()
{
    sf::Image newImage;
    sf::Texture newTexture;
    newImage.loadFromFile(resourcePath() + "Assets/Sprites/Goblin/goblin_idle.png");
    newImage.createMaskFromColor(sf::Color(157, 157, 157));
    newTexture.loadFromImage(newImage);
    SpriteTextures.push_back(newTexture);
    
    newImage.loadFromFile(resourcePath() + "Assets/Sprites/Goblin/goblin_run.png");
    newImage.createMaskFromColor(sf::Color(157, 157, 157));
    newTexture.loadFromImage(newImage);
    SpriteTextures.push_back(newTexture);
    
    newImage.loadFromFile(resourcePath() + "Assets/Sprites/Goblin/goblin_attack.png");
    newImage.createMaskFromColor(sf::Color(157, 157, 157));
    newTexture.loadFromImage(newImage);
    SpriteTextures.push_back(newTexture);
    
    newImage.loadFromFile(resourcePath() + "Assets/Sprites/Goblin/goblin_death.png");
    newImage.createMaskFromColor(sf::Color(157, 157, 157));
    newTexture.loadFromImage(newImage);
    SpriteTextures.push_back(newTexture);
}

void Goblin::initSprite()

{

    Character::setSpriteR(240, 260, 190, 300);
    Character::setTexture(SpriteTextures[0], GOBLIN_SCALE, 0);
    
}

void Goblin::updateAnimation()
{
    switch (Character::getState()) {
        case 0:
        {
            int r1 = Character::getSpriteRect().left;
            Character::setSpriteR(240, 260, 190, 300);
            Character::setTexture(SpriteTextures[0], GOBLIN_SCALE, 0);
            Character::invertSprite();
            if (r1 > 672 * 2)
                r1 = 240;
            else
                
                r1 += 672;
            Character::setSpriteR(r1, 260, 190, 300);
            break;
        }
        case 1:
        {
            int r1 = Character::getSpriteRect().left;
             Character::setSpriteR(240, 260, 190, 300);
            Character::setTexture(SpriteTextures[1], GOBLIN_SCALE, 0);
            if (r1 > 672 * 5)
                r1 = 240;
            else
                
                r1 += 672;
            Character::setSpriteR(r1, 260, 190, 300);
            break;
        }
        case 2:
        {
            int r1 = Character::getSpriteRect().left;
            Character::setSpriteR(240, 260, 190, 300);
            Character::setTexture(SpriteTextures[2], GOBLIN_SCALE, 0);
            if (r1 > 672 * 6)
                r1 = 240;
            else
                
                r1 += 672;
            Character::setSpriteR(r1, 260, 190, 300);
            break;
        }
        case 3:
        {
            int r1 = Character::getSpriteRect().left;
            Character::setSpriteR(240, 260, 250, 300);
            Character::setTexture(SpriteTextures[3], GOBLIN_SCALE, 0);
            Character::invertSprite();
            if (r1 > 672 * 7)
            {
                //r1 = 240;
                Character::setState(-1);
            }
            else
                r1 += 672;
            Character::setSpriteR(r1, 260, 250, 300);
            break;
            
        }
            
        default:
            break;
    }
    
}
