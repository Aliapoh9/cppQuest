#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <list>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Goblin.hpp"
#include "Platform.hpp"
#include "Mercenary.hpp"
#include "Knight.hpp"
#include "Boss.hpp"
#include "Dark_Knight.hpp"


#include "ResourcePath.hpp"



class GameEngine
{
private:
    std::vector<Enemies*> ActiveEnemies;
    std::vector<Enemies*>::iterator EnemyInCombat;
    std::vector<Platform> PlatformToDraw;
    
    std::vector<PartyMember*> PartyMembers;
    
    std::list<Enemies*> EnemyP;
    std::list<Enemies*>::iterator eIt;
    std::list<Enemies*>::iterator eTurn;
    
    sf::RenderWindow window;
    
    sf::Font mainFont;
    sf::Text Cursor;
    sf::RectangleShape transitionR;
    sf::RectangleShape battleMenu;
    sf::RectangleShape target;
    
    double originalX;
    double enemyOGX;
    bool charAttacking = false;
    bool gameOver = false;
    
    bool mainMenu = true;
    bool inBattle = false;
    bool selectingTarget = false;
    bool afterBattle = false;
    int battleTurn = 1;
    int characterTurn = 0;
    int enemyTurn = 0;
    int selection = 0;
    int alivePartyM = 0;
    int deadPartyM = 0;
    
    int damageDealt = 0;
    std::string toWhom;
    
    int earnedEXP = 0;
    int earnedGold = 0;

public:
    GameEngine();
    
    void initGameWindow();
    
    int getCollision(sf::FloatRect s1, sf::FloatRect s2);
    int getStanding(sf::FloatRect s1, sf::FloatRect s2);
    
    void initiateBattle(int type);
    void drawMainBattleMenu();
    void endBattle();
    
    void attack(Character& c1, Character& c2);
    
};

#endif
