//
//  Dark_Knight.hpp
//  au1
//
//  Created by Reynauld on 10/5/2562 BE.
//  Copyright © 2562 Reynauld. All rights reserved.
//

#ifndef Dark_Knight_hpp
#define Dark_Knight_hpp

#include "PartyMember.hpp"

class DarkKnight : public PartyMember
{
public:
    DarkKnight();
    virtual void initSprite();
    virtual void updateAnimation();
    
};



#endif /* Dark_Knight_hpp */
