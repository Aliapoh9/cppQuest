#ifndef Mercenary_hpp
#define Mercenary_hpp

#include "PartyMember.hpp"

class Mercenary : public PartyMember
{
public:
    Mercenary();
    virtual void initSprite();
    virtual void updateAnimation();

};

#endif /* Mercenary_hpp */
