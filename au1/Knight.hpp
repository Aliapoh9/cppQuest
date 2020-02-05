
#ifndef Knight_hpp
#define Knight_hpp

#include "PartyMember.hpp"

class Knight : public PartyMember
{
public:
    Knight();
    virtual void initSprite();
    virtual void updateAnimation();
    
};


#endif /* Knight_hpp */
