#include "Platform.hpp"
#include "ResourcePath.hpp"

Platform::Platform(int x, int y, int w, int h)
{
    Texture.loadFromFile(resourcePath() + "Assets/Sprites/grass.png");
    shape.setTexture(&Texture);
    shape.setSize(sf::Vector2f(h, w));
}

void Platform::setSpriteR(int x, int y, int w, int h)
{
    spriteRect.left = x;
    spriteRect.top = y;
    spriteRect.height = h;
    spriteRect.width = w;
}

void Platform::setPosition(float xOff, float yOff)
{
    shape.setPosition(xOff, yOff);
}

sf::RectangleShape Platform::getShape() const
{
    return shape;
}

sf::FloatRect Platform::getBoundingBox() const
{
    return shape.getGlobalBounds();
}
