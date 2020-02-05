#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include "Character.hpp"
#include <vector>


/*
 Abstract Class of Enemies, with the amount of Experience and gold given to the player upon death
 */

class Enemies : public Character
{
    
protected:
    int expYield;
    int goldYield;
    std::vector<sf::Texture> SpriteTextures;
    
public:
    Enemies(std::string n, int ms, double mh, double d, int expY, int gY) : Character(n, ms, mh, d), expYield(expY), goldYield(gY) {}
    ~Enemies();
    
    virtual void loadTextures() = 0;

    int getExpYield() { return expYield; }
    int getGoldYield() { return goldYield; }
};


#endif
