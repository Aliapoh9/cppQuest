#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"

/*
 Player class as in the overworld, not in battle
 */

class Player : public Character
{
private:
    int Level;
    double Currency;
    int Experience;
    bool Jumping;
public:
    Player(int lv = 1, int exp = 0, double c = 0);
    virtual void initSprite();
    virtual void updateAnimation();
    
    void move(float offX, float offY);
    int getLevel() { return Level; }
    int getExp() { return Experience; }
    double getCurrency() { return Currency; }
    bool canJump() { return !Jumping; }
    
    void setJumping(bool jump);
    void setLevel(int Lvl);
    void setExp(int Exp);
    void setCurrency(double G);
};


#endif
