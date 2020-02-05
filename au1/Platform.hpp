#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SFML/Graphics.hpp>

class Platform
{
private:
    sf::Texture Texture;  // Sprite Sheet
    sf::IntRect spriteRect;
    sf::RectangleShape shape;
    
public:
    Platform(int x, int y, int w, int h);
    void setSpriteR(int x, int y, int w, int h);
    void setPosition(float xOff, float yOff);
    
    sf::Sprite getSprite();
    sf::RectangleShape getShape() const;
    sf::FloatRect getBoundingBox() const;
};


#endif
