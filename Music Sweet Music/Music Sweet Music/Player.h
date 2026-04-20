#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Texture texture;
public:
    Player(float width, float height, float x, float y);

    void setTextureRect(float x, float y);
    void setPosition(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::RectangleShape rectangle;
};

