

#ifndef PartyMember_hpp
#define PartyMember_hpp


#include "Character.hpp"

class PartyMember : public Character
{
private:
    int Level;
    int Experience;
    int ExpReq = 100;
    
public:
    PartyMember(std::string name, int mh, int d, int lv = 1, int exp = 0);
    virtual void initSprite() = 0;
    virtual void updateAnimation() = 0;
    
    void move(float offX, float offY);
    int getLevel() { return Level; }
    int getExp() { return Experience; }
    
    void setLevel(int Lvl);
    void setExp(int Exp);
};


#endif /* PartyMember_hpp */
