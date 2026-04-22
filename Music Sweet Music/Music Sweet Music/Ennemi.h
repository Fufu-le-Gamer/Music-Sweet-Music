#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Ennemi
{
private:
    sf::Texture texture;
    sf::IntRect frameRect;

    int currentFrame = 0;
    int maxFrames = 2;
    float frameTime = 0.15f;
    float timer = 0.f;

public:
    Ennemi(float width, float height, float x, float y);

    void update(float dt);
    void draw(sf::RenderWindow& window);

    sf::RectangleShape rectangle;
};
