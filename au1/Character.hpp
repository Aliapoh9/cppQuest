#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <ostream>

/**
 Character class holds the sprite sheet and the sprite itself for that particular character,
 while providing basic characteristics that all characters should have.
 It is an abstract class.
*/

class Character
{
private:
    sf::Texture Texture;  // Sprite Sheet
    sf::Sprite Sprite;
    sf::IntRect spriteRect;
    sf::Clock frameTime;
    
    std::string Name;
    int MovementSpeed;
    int Standing;
    float accelY;
    float velY = 0;
    float terminalVel;
    int CurrentHealth;
    int MaxHealth;
    double Damage;
    bool blocking = false;
    int State = 0;   // 0 For Idle
public:
    Character(std::string n, int ms, int mh, double d) : Name(n), MovementSpeed(ms), CurrentHealth(mh), MaxHealth(mh), Damage(d) {}
    
    virtual void initSprite() = 0;
    virtual void updateAnimation() = 0;
    
    void move(float offX, float offY);
    
    void setTexture(std::string FileName, double scale, double rotate);
    void setColor(sf::Color c);
    void setPosition(float x, float y);
    void setTexture(sf::Texture& t, double scale, double rotate);
    void setSpriteR(int x, int y, int h, int w);
    void setStanding(int newStanding);
    void setHealth(int newHealth);
    void setMaxHealth(int newMH);
    void setDamage(int newDMG);
    void setBlock(bool block);
    void setState(int newState);
    void setAccelY(float newAY);
    void setVelY(float newY);
    void setTerminalVel(float newTVel);
    void invertSprite();
    
    sf::Sprite getSprite();
    sf::Vector2f getPosition();
    sf::IntRect getSpriteRect();
    double updateTime();
    void resetClock();
    
    std::string getName() { return Name; }
    int getMovementSpeed() {return MovementSpeed;}
    int getStanding() { return Standing; }
    float getAccelY() { return accelY; }
    float getVelY() { return velY; }
    float getTerminalVel() { return terminalVel; }
    int getMaxHealth() { return MaxHealth; }
    int getCurrentHealth() { return CurrentHealth;}
    double getDamage() { return Damage; }
    int getState() { return State; }
    bool isBlocking() { return blocking; }
};


static std::ostream& operator<< (std::ostream& strm, Character& c)
{
    strm << c.getName() << " HP: " << std::to_string(c.getCurrentHealth()) << std::endl;
    
    return strm;
}



#endif
