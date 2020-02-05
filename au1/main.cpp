#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

#include "Player.hpp"
#include "Platform.hpp"
#include "Goblin.hpp"
#include "GameEngine.hpp"

#include "ResourcePath.hpp"



/*

int getStanding(sf::FloatRect s1, sf::FloatRect s2)
{
    //(s1.top < s2.top)
    if ((s1.top + s1.height > s2.top) && (s1.top + s1.height - 10 < s2.top) && (s1.left + s1.width > s2.left) && (s1.left < s2.left + s2.width) && s1.intersects(s2))      // On top
    {
        return 1;
    }
    
    return 0;
}

int getCollision(sf::FloatRect s1, sf::FloatRect s2)
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




int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 960), "Shattered");
    
    sf::View view1;
    

    


    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    std::vector<sf::Texture> bg;
    sf::Sprite back;
    
    int bgC = 0;
    
    for (int i = 0; i < 64; i++)
    {
        sf::Texture n;
        n.loadFromFile(resourcePath() + "Assets/Bg1/" +std::to_string(i) + ".png");
        bg.push_back(n);
    }
    
    back.scale(2.6, 3.2);
    
    
    sf::Clock clock;
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "Assets/CyberpunkWaifus.ttf")) {
        return EXIT_FAILURE;
    }

    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile(resourcePath() + "FF5_Victory_(Fanfare)" + ".ogg")) {
//        return EXIT_FAILURE;
//    }
    
    // Play the music
    //music.play();
    
    Player p1 = Player();
    
    Goblin g1 = Goblin();
    
    g1.move(200, 200);
    
    p1.move(30, 0);
    
    Platform plat = Platform(50, 100, 10, 500);
    Platform plat2 = Platform(0, 0, 400, 100);
    
    plat.setPosition(0, 500);
    plat2.setPosition(500, 50);
    
    sf::Clock tickRate;
    
    // Start the game loop
    while (window.isOpen())
    {
        
        // Process events
        sf::Event event;
        
        window.setFramerateLimit(60);
    
        
        //Prints FPS
       // std::cout << 1.0/tickRate.getElapsedTime().asSeconds() << std::endl;
        
        float deltaT = tickRate.restart().asSeconds();
        
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A) && (p1.getState() != 3) )
            {
                p1.setState(0);
            }
            
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
    
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            p1.setState(3);
        }
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            p1.setState(3);
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (p1.canJump())
            {
                p1.setJumping(true);
                p1.setVelY(-500);
                p1.move(0, p1.getVelY() * deltaT);
            }
        }
        
        if (p1.updateTime() > 0.1f)
        {
            p1.updateAnimation();
            g1.updateAnimation();
            p1.resetClock();
        }
        
        if (clock.getElapsedTime().asSeconds() > 0.05f)
        {
            ++bgC;
            
            if (bgC > 63)
                bgC = 0;
            
            back.setTexture(bg[bgC]);
            clock.restart();
        }
        
        sf::Rect<float> inter;
        
        int col = getCollision(p1.getSprite().getGlobalBounds(), plat2.getBoundingBox());
        int col2 = getStanding(p1.getSprite().getGlobalBounds(), plat.getBoundingBox());
        int col3 = getStanding(p1.getSprite().getGlobalBounds(), plat2.getBoundingBox());
        
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
        
        if (col2 == 0 && col3 == 0)
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

        
        view1.reset(sf::FloatRect(p1.getSprite().getPosition().x - 300, p1.getSprite().getPosition().y - 150, 600.f, 300.f));
        //window.setView(view1);

        // Clear screen
        window.clear();
        window.draw(back);

        
        window.draw(g1.getSprite());
        
        // Draw the sprite
        window.draw(plat.getShape());
        window.draw(plat2.getShape());
        window.draw(p1.getSprite());

        // Draw the string

        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
    
    
}
*/

int main()
{
    GameEngine();
    
    
    return 0;
}


