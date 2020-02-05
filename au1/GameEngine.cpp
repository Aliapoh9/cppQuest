//
//  GameEngine.cpp
//  au1
//
//  Created by Reynauld on 5/5/2562 BE.
//  Copyright © 2562 Reynauld. All rights reserved.
//

#include "GameEngine.hpp"


GameEngine::GameEngine() : window(sf::VideoMode(1280, 960), "Cpp quest")
{
    transitionR.setSize(sf::Vector2f(1280, 960));
    transitionR.setFillColor(sf::Color(0,0,0,255));
    
    battleMenu.setSize(sf::Vector2f(1280, 800));
    battleMenu.setFillColor(sf::Color(0,0,0));
    battleMenu.setPosition(0, 500);
    
    mainFont.loadFromFile(resourcePath() + "Assets/CyberpunkWaifus.ttf");
    
    Cursor.setString(">");
    Cursor.setCharacterSize(40);
    Cursor.setFont(mainFont);
    Cursor.setPosition(100, 550);
    
    srand(time(NULL));
    
    initGameWindow();
}

void GameEngine::initGameWindow()
{

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    std::vector<sf::Texture> bg;
    std::vector<sf::Texture> bg2;
    std::vector<sf::Texture> mainBg;

    sf::Sprite back;
    sf::Sprite back2;
    sf::Sprite mainBack;
    back.scale(2.1, 4.5);
    back2.scale(1.4, 1.4);
    back2.move(0, -70);
    mainBack.scale(2.6, 3.4);
    
    int bgC = 0;
    int bg2C = 0;
    int mainBgC = 0;
    
    for (int i = 0; i < 4; i++)
    {
        sf::Texture n;
        n.loadFromFile(resourcePath() + "Assets/bg3/" +std::to_string(i) + ".png");
        bg.push_back(n);
    }
    
    for (int i = 0; i < 55; i++)
    {
        sf::Texture n;
        n.loadFromFile(resourcePath() + "Assets/bg2/" +std::to_string(i) + ".png");
        bg2.push_back(n);
    }
    
    for (int i = 0; i < 63; i++)
    {
        sf::Texture n;
        n.loadFromFile(resourcePath() + "Assets/mainBg/" +std::to_string(i) + ".png");
        mainBg.push_back(n);
    }

    back.setTexture(bg[bgC]);
    back2.setTexture(bg2[bg2C]);
    mainBack.setTexture(mainBg[mainBgC]);
    
    sf::Clock bgClock;
    sf::Clock afterBattleClock;
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "Assets/CyberpunkWaifus.ttf")) {
        return EXIT_FAILURE;
    }
    
    sf::Text BattleBegin("BATTLE START!", font, 50);
    BattleBegin.setFillColor(sf::Color::White);
    BattleBegin.setPosition(480, 460);
    
    sf::Music battleMusic;
    sf::SoundBuffer hit;
    sf::Sound hitSound;
    sf::Music victory;
    sf::SoundBuffer strongHit;
    sf::Sound strongHitSound;
    sf::SoundBuffer select;
    sf::Sound selectSound;
    
    battleMusic.setVolume(30);
    victory.setVolume(40);
    strongHitSound.setVolume(40);
    battleMusic.setLoop(true);
    //selectSound.setVolume(200);
    
    hit.loadFromFile(resourcePath() + "Assets/Sounds/hit.wav");
    strongHit.loadFromFile(resourcePath() + "Assets/Sounds/strongHit.wav");
    select.loadFromFile(resourcePath() + "Assets/Sounds/select.wav");
    
    hitSound.setBuffer(hit);
    strongHitSound.setBuffer(strongHit);
    selectSound.setBuffer(select);
    
    if (!battleMusic.openFromFile(resourcePath() + "Assets/Sounds/battle.ogg"))
    {
        return EXIT_FAILURE;
    }
    
    if (!victory.openFromFile(resourcePath() + "Assets/Sounds/ff7.ogg"))
    {
        return EXIT_FAILURE;
    }

    sf::View PlayerView(sf::FloatRect(200.f, 200.f, 300.f, 200.f));

    
    Player p1 = Player();
    
    Knight k1 = Knight();
    DarkKnight k2 = DarkKnight();
    Knight k3 = Knight();
    Mercenary k4 = Mercenary();
    
    PartyMembers.push_back(&k1);
    PartyMembers.push_back(&k2);
    PartyMembers.push_back(&k3);
    PartyMembers.push_back(&k4);
    
    Goblin g1 = Goblin();
    Goblin g2 = Goblin();
    Goblin g3 = Goblin();
    Goblin g4 = Goblin();
    Goblin g5 = Goblin();
    Goblin g6 = Goblin();
    Goblin g7 = Goblin();
    Goblin g8 = Goblin();
    Goblin g9 = Goblin();
    Goblin g10 = Goblin();
    Goblin g11 = Goblin();
    Goblin g12 = Goblin();
    
    Boss b1 = Boss();
    
    eIt = EnemyP.begin();
    eTurn = EnemyP.begin();
    
    
    g1.move(200, 200);
    g2.move(400, 700);
    g3.move(600, 700);
    
    g4.move(100, 200);
    g5.move(500, 400);
    g6.move(300, 20);
    g8.move(500, 20);
    g9.move(600, 20);
    g10.move(700, 20);
    g11.move(1150, 300);
    g12.move(1200, 300);
    g7.move(100, 600);
    
    b1.move(1200, 10);
    
    p1.move(20, 700);
    
    ActiveEnemies.push_back(&g1);
    ActiveEnemies.push_back(&g2);
    ActiveEnemies.push_back(&g3);
    ActiveEnemies.push_back(&g4);
    ActiveEnemies.push_back(&g5);
    ActiveEnemies.push_back(&g6);
    ActiveEnemies.push_back(&g7);
    ActiveEnemies.push_back(&g8);
    ActiveEnemies.push_back(&g9);
    ActiveEnemies.push_back(&g10);
    ActiveEnemies.push_back(&g11);
    ActiveEnemies.push_back(&g12);
    
    ActiveEnemies.push_back(&b1);
    
    Platform plat(0, 0, 70, 200);  // FLOOR PLATFORM
    Platform plat2(0, 0, 70, 250);
    Platform plat3(0, 0, 30, 200);
    Platform plat4(0, 0, 40, 400);
    Platform plat5(0, 0, 40, 100);
    
    Platform plat6(0, 0, 40, 90);
    Platform plat7(0, 0, 40, 60);
    Platform plat8(0, 0, 40, 60);
    Platform plat9(0, 0, 40, 60);
    Platform plat10(0, 0, 60, 600);
    
    Platform plat11(0, 0, 170, 400);
    
    Platform plat12(0, 0, 20, 100);
    Platform plat13(0, 0, 20, 100);
    Platform plat14(0, 0, 20, 100);
    Platform plat15(0, 0, 20, 100);
    Platform plat16(0, 0, 20, 100);
    Platform plat17(0, 0, 20, 100);
    
    plat.setPosition(0, 870);
    plat2.setPosition(300, 870);
    plat3.setPosition(560, 790);
    plat5.setPosition(700, 650);
    plat6.setPosition(1200, 200);

    plat7.setPosition(870, 500);
    
    plat8.setPosition(850, 725);
    plat9.setPosition(450, 600);
    
    plat10.setPosition(500, 200);
    plat11.setPosition(1000, 750);
    plat12.setPosition(0, 600);
    plat13.setPosition(0, 500);
    plat14.setPosition(0, 400);
    plat15.setPosition(0, 300);
    plat16.setPosition(100, 200);
    plat17.setPosition(250, 200);
    
    
    plat4.setPosition(0, 710); // TOP OF SPAWN PLAT

    
    PlatformToDraw.push_back(plat);
    PlatformToDraw.push_back(plat2);
    PlatformToDraw.push_back(plat3);
    PlatformToDraw.push_back(plat4);
    PlatformToDraw.push_back(plat5);
    PlatformToDraw.push_back(plat6);
    PlatformToDraw.push_back(plat7);
    PlatformToDraw.push_back(plat8);
PlatformToDraw.push_back(plat9);
    PlatformToDraw.push_back(plat10);
     PlatformToDraw.push_back(plat11);
    PlatformToDraw.push_back(plat12);
    PlatformToDraw.push_back(plat13);
    PlatformToDraw.push_back(plat14);
    PlatformToDraw.push_back(plat15);
    PlatformToDraw.push_back(plat16);
    PlatformToDraw.push_back(plat17);
    
    
    sf::Clock tickRate;
    sf::Clock enemyDelay;
    
    window.setFramerateLimit(60);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        //Prints FPS
        //std::cout << 1.0/tickRate.getElapsedTime().asSeconds() << std::endl;
        
        float deltaT = tickRate.restart().asSeconds();
        
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A) && (p1.getState() != 3) && !inBattle )
            {
                p1.setState(0);
            }
            
            if (event.type == sf::Event::KeyPressed && mainMenu)
            {
                mainMenu = false;
            }
            
            if (inBattle && !selectingTarget && !enemyTurn)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                {
                    if (Cursor.getPosition().y <= 550)
                    {
                        selection = 1;
                        Cursor.setPosition(Cursor.getPosition().x, 650);
                    }
                    else
                    {
                        selection -= 1;
                        Cursor.move(0, -100);
                    }
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                {
                    if (Cursor.getPosition().y >= 650)
                    {
                        Cursor.setPosition(Cursor.getPosition().x, 550);
                        selection = 0;
                    }
                    else
                    {
                        Cursor.move(0, 100);
                        selection += 1;
                    }
                }
                
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && !charAttacking)
                {
                    selectSound.play();
                    switch (selection)
                    {
                            
                        case 0:
                        {
                            selectingTarget = true;
                            break;
                        }
                        case 1:
                        {
                            if (characterTurn == 3)
                            {
                                PartyMembers[characterTurn]->setBlock(true);
                                characterTurn = 0;
                                enemyTurn = 1;
                            }
                            else
                            {
                                PartyMembers[characterTurn]->setBlock(true);
                                characterTurn += 1;
                            }
                            break;
                        }
                    }
                }
            
            }
            
            else if (selectingTarget)
            {
                
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X)
                {
                    selectingTarget = false;
                    eIt = EnemyP.begin();
                    selection = 0;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                {
                    eIt--;

                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                {
                    eIt++;
                }
            
                
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && eIt != EnemyP.end())
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (PartyMembers[i]->getCurrentHealth() > 0)
                        {
                            alivePartyM += 1;
                        }
                    }
                    
                    originalX = PartyMembers[characterTurn]->getPosition().x;
                    
                    PartyMembers[characterTurn]->setState(4);
                    charAttacking = true;
                    attack(*PartyMembers[characterTurn], **eIt);
                    selection = 0;
                    characterTurn += 1;
                    if (characterTurn > alivePartyM-1)
                    {
                        characterTurn = 0;
                        enemyTurn = 1;
                    }
                    selectingTarget = false;
                    alivePartyM = 0;
                    
                }
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        if (!inBattle)
        
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if ((p1.getState() != 3) && (p1.canJump()))
                    p1.setState(2);
                p1.move(-p1.getMovementSpeed() * deltaT, 0);
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                if ((p1.getState() != 3) && (p1.canJump()))
                    p1.setState(1);
                p1.move(p1.getMovementSpeed() * deltaT, 0);
            }
 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                if (p1.canJump())
                {
                    p1.setJumping(true);
                    p1.setVelY(-300);
                    p1.move(0, p1.getVelY() * deltaT);
                }
            }
            
            //
            //
            //
            //END OF EVENT PROCESSING
            //
            //
            //
            
            if (p1.updateTime() > 0.1f)
            {
                p1.updateAnimation();
                for (const auto& e : ActiveEnemies)
                {
                    e->updateAnimation();
                }
                p1.resetClock();
            }
            
        }
        
   //     std::cout << characterTurn << std::endl;

        
        if (p1.updateTime() > 0.1f) // In battle animation update
        {
            for (const auto& pm : PartyMembers)
            {
                if (pm->getState() == 4)
                {
                    //std::cout << pm->getPosition().x << std::endl;

                    if (pm->getPosition().x < originalX + 100 && charAttacking)
                        pm->move(70, 0);
                    else if (pm->getPosition().x <= originalX)
                    {
                        pm->setState(0);
                        pm->setPosition(originalX, pm->getPosition().y);
                    }
                    else
                    {
                        strongHitSound.play();
                        charAttacking = false;
                        pm->move(-70, 0);
                    }
                }
                pm->updateAnimation();
            }
            for (const auto& e : EnemyP)
            {
                if (e->getState() == 4)
                {
                    //std::cout << pm->getPosition().x << std::endl;
                    
                    if (e->getPosition().x > enemyOGX - 100 && charAttacking)
                        e->move(-70, 0);
                    else if (e->getPosition().x >= enemyOGX)
                    {
                        e->setState(0);
                        e->setPosition(enemyOGX, e->getPosition().y);
                    }
                    else
                    {
                        hitSound.play();
                        charAttacking = false;
                        e->move(70, 0);
                    }
                }
                e->updateAnimation();
            }
            p1.resetClock();
        }
        
        if (mainMenu)
        {
            if (bgClock.getElapsedTime().asSeconds() > 0.15f) // Background animation update
            {
                ++mainBgC;
                
                if (mainBgC > 62)
                    mainBgC = 0;
                
                mainBack.setTexture(mainBg[mainBgC]);
                bgClock.restart();
            }
        }

        if (inBattle)
            {
                if (bgClock.getElapsedTime().asSeconds() > 0.15f) // Background animation update
                {
                    ++bg2C;
                    
                    if (bg2C > 54)
                        bg2C = 0;
                    
                    back2.setTexture(bg2[bg2C]);
                    bgClock.restart();
                }
            }
        else
        {
            if (bgClock.getElapsedTime().asSeconds() > 0.15f) // Background animation update
            {
                ++bgC;
                
                if (bgC > 3)
                    bgC = 0;
                
                back.setTexture(bg[bgC]);
                bgClock.restart();
            }
            
        }
        
        /*
        //
        //
        // End of animation update
        //
        //
        //
         */
        
    
        if (!inBattle)
        {
            if (p1.getPosition().y > 1270)
            {
                afterBattleClock.restart();
                gameOver = true;
            }
            int col = 0;
            
            if (gameOver)
            {
                p1.setPosition(-100, -100);
                if (afterBattleClock.getElapsedTime().asSeconds() >= 5.0f)
                {
                    window.close();
                }
            }
            
            for (auto it = ActiveEnemies.begin(); it != ActiveEnemies.end(); ++it)
            {
                if (getCollision(p1.getSprite().getGlobalBounds(), (*it)->getSprite().getGlobalBounds()) )
                {
                    //std::cout << "BATTLE!" << std::endl;
                    EnemyInCombat = it;
                    battleMusic.play();
                    if ((*it)->getName() == "Uproar")
                    {
                        initiateBattle(2);
                    }
                    else
                        initiateBattle(1);

                }
            }
            
            for (const auto& platform : PlatformToDraw)
            {
                if (col == 0)
                    col = getCollision(p1.getSprite().getGlobalBounds(), platform.getBoundingBox());
                if (p1.getSprite().getGlobalBounds().intersects(platform.getBoundingBox()))
                    {
                        p1.setStanding(p1.getStanding() + getStanding(p1.getSprite().getGlobalBounds(), platform.getBoundingBox()));
                    }
                
                for (const auto& e : ActiveEnemies)
                {
                    if (e->getSprite().getGlobalBounds().intersects(platform.getBoundingBox()))
                    {
                        e->setStanding(e->getStanding() + getStanding(e->getSprite().getGlobalBounds(), platform.getBoundingBox()));
                    }
                }
                
            }
            if (p1.getPosition().x < 10)
            {
                p1.move(p1.getMovementSpeed() * deltaT, 0);
            }
            
            if (col == 1)
            {
                p1.move(-p1.getMovementSpeed() * deltaT, 0);
            }
            else if (col == 2)
            {
                p1.move(p1.getMovementSpeed() * deltaT, 0);
            }
            else if (col == 3)
            {
                p1.move(0, p1.getVelY() * deltaT);
            }
            
            for (const auto& e : ActiveEnemies)
            {
                if (!e->getStanding())
                {
                    if (e->getVelY() >= e->getTerminalVel())
                        e->setVelY(e->getTerminalVel());
                    else
                        e->setVelY(e->getVelY() + e->getAccelY());
                    e->move(0, e->getVelY() * deltaT);
                }
                else
                {
                    e->setVelY(0);
                }
                
                e->setStanding(0);
            }
            
            if (p1.getStanding() == 0)
            {
                if (p1.getVelY() >= p1.getTerminalVel())
                    p1.setVelY(p1.getTerminalVel());
                else
                    p1.setVelY(p1.getVelY() + p1.getAccelY());
                p1.move(0, p1.getVelY() * deltaT);
            }
            else
            {
                p1.setJumping(false);
                p1.setVelY(0);
            }
            
            p1.setStanding(0);
            
        }
        
        else   // IN BATTLE LOGIC
        {
            
            for (int i = 0; i < 4; i++)
            {
                if (PartyMembers[i]->getCurrentHealth() <= 0)
                {
                    deadPartyM += 1;
                }
            }
            
            if (deadPartyM == 4)
            {
                battleMusic.stop();
                gameOver = true;
                inBattle = false;
                selectingTarget = false;
                afterBattle = false;
                afterBattleClock.restart();
            }
            else
                deadPartyM = 0;
            
            if (characterTurn > 3)
                characterTurn = 0;
            
            if (PartyMembers[characterTurn]->getCurrentHealth() <= 0)
            {
                if (characterTurn > 3)
                    characterTurn = 0;
                else
                    characterTurn += 1;
            }
            
            for (auto it = EnemyP.begin(); it != EnemyP.end(); it++)
            {

                if ((*it)->getCurrentHealth() <= 0)
                {
                    earnedEXP += (*it)->getExpYield();
                    earnedGold += (*it)->getGoldYield();
                    it = EnemyP.erase(it);
                    eIt = EnemyP.begin();
                    eTurn = EnemyP.begin();
                }
            }
            if (eTurn == EnemyP.end())
            {
                eTurn = EnemyP.begin();
                enemyTurn = 0;
                battleTurn += 1;
            }
            
            if (enemyTurn && enemyDelay.getElapsedTime().asSeconds() > 1.5f)
            {
                
                int t = rand() % 4;
                while (PartyMembers[t]->getCurrentHealth() <= 0)
                {
                    t = rand() % 4;
                }
                enemyOGX = (*eTurn)->getPosition().x;
                (*eTurn)->setState(4);
                charAttacking = true;
                attack(**eTurn, *PartyMembers[t]);
                ++eTurn;
                enemyDelay.restart();
            }

            
            
            if (EnemyP.empty()) // All enemies died, Battle WON.
            {
                p1.setState(0);
                endBattle();
                battleMusic.stop();
                victory.play();
                afterBattleClock.restart();
                ActiveEnemies.erase(EnemyInCombat);
            }
        
        }

        // Clear screen
        window.clear();
        
        if (gameOver)
        {
            window.setView(window.getDefaultView());
            window.draw(mainBack);
            sf::Text yd("YOU DIED", mainFont, 100);
            yd.setFillColor(sf::Color::Red);
            yd.move(150, 200);
            window.draw(yd);
            
            sf::Text score("Your score is: " + std::to_string(p1.getCurrency()), mainFont, 60);
            score.move(150, 500);
            window.draw(score);
        }
        
        if (mainMenu)
        {
            window.draw(mainBack);
            sf::Text name("CPP QUEST", mainFont, 100);
            name.move(200, 200);
            window.draw(name);
            
            sf::Text Press("Press any button to Start!", mainFont, 50);
            Press.move(100, 500);
            window.draw(Press);
        }
        
        if (inBattle)
        {
            window.setView(window.getDefaultView());
            window.draw(back2);
        }
        else if (!mainMenu && !gameOver &&!afterBattle)
        {
            back.setScale(0.5, 0.9);
            window.draw(back);
            back.setPosition(p1.getPosition().x - 100, p1.getPosition().y - 100);
            PlayerView.reset(sf::FloatRect(p1.getPosition().x - 100, p1.getPosition().y - 100, 300, 200));
            sf::RectangleShape t(sf::Vector2f(300, 200));
            t.setOutlineColor(sf::Color::Red);
            t.setFillColor(sf::Color::Transparent);
            t.setOutlineThickness(2);
            t.setPosition(p1.getPosition().x - 100, p1.getPosition().y - 100);
            //window.draw(t);
            window.setView(PlayerView);
        }
        
        if (inBattle)
        {
            float CharY = 290.f;
            float CharX = 300.f;
            
            float EnemyY = 300.f;
            float EnemyX = 1000.f;
            
            float nameY = 550;
            
            window.draw(battleMenu);
            
            for (int i = 0; i < 4; i++)
            {
                sf::Text status1;
                status1.setFont(font);
                status1.setCharacterSize(35);
                
                if (PartyMembers[i]->getCurrentHealth() <= 0)
                {
                    continue;
                }
                
                if (characterTurn == i && !enemyTurn)
                {
                    status1.setString("<< LV: " + std::to_string(PartyMembers[i]->getLevel()) + " " +  PartyMembers[i]->getName() + " HP: " + std::to_string(PartyMembers[i]->getCurrentHealth()) + " >>");
                }
                else
                {
                    status1.setString("LV: " + std::to_string(PartyMembers[i]->getLevel()) + " " + PartyMembers[i]->getName() + " HP: " + std::to_string(PartyMembers[i]->getCurrentHealth()));
                }
                status1.setPosition(600, nameY);
                nameY += 100;
                window.draw(status1);
            }
            
            for (auto& m : PartyMembers)
            {
                if(m->getCurrentHealth() > 0)
                    window.draw(m->getSprite());
            }
            
            for (const auto& e : EnemyP)
            {
                if (e->getState() != -1)
                    window.draw(e->getSprite());
            }
            
            if (selectingTarget)
            {
                    if (eIt != EnemyP.end())
                    {
                        target.setPosition((*eIt)->getPosition().x - (*eIt)->getSprite().getGlobalBounds().width / 2, (*eIt)->getPosition().y);
                        target.setSize(sf::Vector2f((*eIt)->getSprite().getGlobalBounds().width, (*eIt)->getSprite().getGlobalBounds().height));
                        target.setOutlineColor(sf::Color::Red);
                        target.setOutlineThickness(2);
                        target.setFillColor(sf::Color::Transparent);
                        window.draw(target);
                    }

            }
            
            else if (enemyTurn)
            {
                sf::Text EnemyAct("ENEMY ACTION", font , 60);
                EnemyAct.setPosition(150, 550);
                EnemyAct.setFillColor(sf::Color::Red);
                window.draw(EnemyAct);
            }
            
            else
            {
                drawMainBattleMenu();
            }
            
            
            if (transitionR.getFillColor().a > 2)
            {
                transitionR.setFillColor(sf::Color(0,0,0, transitionR.getFillColor().a - 2));
                BattleBegin.setFillColor(sf::Color(255, 255, 255, BattleBegin.getFillColor().a - 2));
                window.draw(transitionR);
                window.draw(BattleBegin);
            }
            
            sf::Text turn("Damage: " + std::to_string(damageDealt) + " to " + toWhom, mainFont, 40);
            turn.setFillColor(sf::Color::Red);
            turn.setPosition(100, 900);
            window.draw(turn);
            
        }
        else if (afterBattle)
        {
            window.setView(window.getDefaultView());
            window.draw(back2);
            if (afterBattleClock.getElapsedTime().asSeconds() < 8.f)
            {
                sf::Text win("VICTORY!", font , 60);
                win.setPosition(150, 550);
                window.draw(win);
                sf::Text exp("EXP EARNED: " + std::to_string(earnedEXP), font , 60);
                exp.setPosition(150, 750);
                window.draw(exp);
                sf::Text gold("GOLD EARNED: " + std::to_string(earnedGold), font , 60);
                gold.setPosition(150, 830);
                p1.setCurrency(p1.getCurrency() + earnedGold);
                window.draw(gold);
            }
            else
            {
                victory.stop();
                earnedEXP = 0;
                earnedGold = 0;
                afterBattle = 0;
            }
        }

        else if (!mainMenu && !gameOver)
        {
            for (const auto& e : ActiveEnemies)
            {
                window.draw(e->getSprite());
            }
            
            for (const auto& platform : PlatformToDraw)
            {
                window.draw(platform.getShape());
            }
            
            window.draw(p1.getSprite());
        }

        
        window.display();
    }
    
    return EXIT_SUCCESS;
    
}


int GameEngine::getCollision(sf::FloatRect s1, sf::FloatRect s2)
{
    
    if ( (s1.left + s1.width > s2.left) &&     (s1.left < s2.left) && !getStanding(s1, s2) && s1.intersects(s2))       // On the left
    {
        return 1;
    }
    
    else if ((s1.left < s2.left + s2.width) && (s1.left + s1.width > s2.left + s2.width) && !getStanding(s1, s2) && s1.intersects(s2))     // On the Right
    {
        return 2;
    }
    
    else if (s1.top < s2.top + s2.height && s1.intersects(s2) && !getStanding(s1, s2))
    {
        return 3;
    }
    
    return 0;
}

int GameEngine::getStanding(sf::FloatRect s1, sf::FloatRect s2)
{
    //(s1.top < s2.top)
    if ((s1.top + s1.height > s2.top) && (s1.top + s1.height - 10 < s2.top) && (s1.left + s1.width > s2.left) && (s1.left < s2.left + s2.width) && s1.intersects(s2))      // On top
    {
        return 1;
    }
    
    return 0;
}

void GameEngine::initiateBattle(int type)
{
    int amountOfEnemy = (rand() % 4) + 1;
    
    if (type == 1)
    {
        for (int i = 0; i < amountOfEnemy; i++)
        {
            Goblin* newG = new Goblin();
            EnemyP.push_back(newG);
        }
    }
    else if (type == 2)
    {
        Boss* newB = new Boss();
        EnemyP.push_back(newB);
    }
    
    eIt = EnemyP.begin();
    
    if (!inBattle)
    {
        transitionR.setFillColor(sf::Color(0,0,0, 255));
        float CharY = 290.f;
        float CharX = 300.f;
        
        float EnemyY = 300.f;
        float EnemyX = 1000.f;
        
        for (auto& m : PartyMembers)
        {
            m->setPosition(CharX, CharY);
            CharY += 20;
            CharX -= 50;
        }
        
        for (const auto& e : EnemyP)
        {
            e->setPosition(EnemyX, EnemyY);
            EnemyY += 20;
            EnemyX += 50;
        }
        
        inBattle = true;
    }
}

void GameEngine::attack(Character& c1, Character& c2)  // c1 is the attacking side, c2 defending.
{
    int damage;
    if (c2.isBlocking())
        damage = c1.getDamage() * 0.7;
    else
        damage = c1.getDamage();
    toWhom = c2.getName();
    damageDealt = damage;
    c2.setHealth(c2.getCurrentHealth() - damage);
}

void GameEngine::drawMainBattleMenu()
{
    window.draw(Cursor);
    sf::Text Attack("Attack", mainFont, 40);
    Attack.setPosition(200, 550);
    window.draw(Attack);
    
    sf::Text Block("Block", mainFont, 40);
    Block.setPosition(200, 650);
    window.draw(Block);
}

void GameEngine::endBattle()
{
    inBattle = false;
    selectingTarget = false;
    afterBattle = true;
    selection = 0;
    battleTurn = 1;
    characterTurn = 0;
    eIt = EnemyP.begin();
    
    for (const auto& pm : PartyMembers)
    {
        if (pm->getCurrentHealth() <= 0)
            pm->setHealth(1);
        pm->setExp(pm->getExp() + earnedEXP);
    }
}
