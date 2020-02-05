#include "Character.hpp"
#include "ResourcePath.hpp"

void Character::move(float offX, float offY)
{
    Sprite.move(offX, offY);
}

void Character::setTexture(std::string FileName, double scale, double rotate)
{
    Texture.loadFromFile(resourcePath() + FileName);
    Sprite.setTexture(Texture);
    Sprite.setOrigin(spriteRect.width / 2 , 0);
    Sprite.setScale(scale, scale);
    Sprite.setRotation(rotate);
    Sprite.setTextureRect(spriteRect);
}

void Character::setTexture(sf::Texture& t, double scale, double rotate)
{
    Sprite.setTexture(t);
    Sprite.setOrigin(spriteRect.width / 2 , 0);
    Sprite.setScale(scale, scale);
    Sprite.setRotation(rotate);
    Sprite.setTextureRect(spriteRect);
}

void Character::invertSprite()
{
    Sprite.setScale(-1 * Sprite.getScale().x, Sprite.getScale().y);
}

void Character::setSpriteR(int x, int y, int w, int h)
{
    spriteRect.left = x;
    spriteRect.top = y;
    spriteRect.height = h;
    spriteRect.width = w;
    Sprite.setTextureRect(spriteRect);
}

void Character::setColor(sf::Color c)
{
    Sprite.setColor(c);
}

void Character::setPosition(float x, float y)
{
    Sprite.setPosition(x, y);
}

void Character::setAccelY(float newAY)
{
    accelY = newAY;
}

void Character::setVelY(float newY)
{
    velY = newY;
}
void Character::setStanding(int newStanding)
{
    Standing = newStanding;
}

void Character::setHealth(int newHealth)
{
    CurrentHealth = newHealth;
}

void Character::setMaxHealth(int newMH)
{
    MaxHealth = newMH;
}

void Character::setDamage(int newDMG)
{
    Damage = newDMG;
}

void Character::setTerminalVel(float newTVel)
{
    terminalVel = newTVel;
}

void Character::setState(int newState)
{
    State = newState;
}

double Character::updateTime()
{
    double t = frameTime.getElapsedTime().asSeconds();
    return t;
}

void Character::resetClock()
{
    frameTime.restart();
}

sf::Sprite Character::getSprite()
{
    return Sprite;
}

sf::IntRect Character::getSpriteRect()
{
    return spriteRect;
}

sf::Vector2f Character::getPosition()
{
    return Sprite.getPosition();
}

void Character::setBlock(bool block)
{
    blocking = block;
}

