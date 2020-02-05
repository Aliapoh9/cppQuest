
#ifndef Boss_hpp
#define Boss_hpp

#include "Enemies.hpp"
#include "ResourcePath.hpp"

class Boss : public Enemies
{
public:
    Boss();
    virtual void loadTextures();
    
    virtual void initSprite();
    virtual void updateAnimation();
};


#endif /* Boss_hpp */
