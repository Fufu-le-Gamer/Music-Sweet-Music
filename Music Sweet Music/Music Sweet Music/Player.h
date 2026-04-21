#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
    float x, y;
    sf::Texture texture;
public:
    Player(float width, float height, float x, float y);
    ~Player() = default;

    void setTextureRect(float x, float y);
    void setPosition(float x, float y);

    void draw(sf::RenderWindow& window);

    float getPosX() const { return rectangle.getPosition().x; }
    float getPosY() const { return rectangle.getPosition().y; }

    sf::RectangleShape rectangle;
};

