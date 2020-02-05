#ifndef Goblin_hpp
#define Goblin_hpp

#include "Enemies.hpp"
#include "ResourcePath.hpp"

class Goblin : public Enemies
{    
public:
    Goblin();
    virtual void loadTextures();
    
    virtual void initSprite();
    virtual void updateAnimation();
};




#endif /* Goblin_hpp */
