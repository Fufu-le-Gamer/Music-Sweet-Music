#include "Goal.h"
#include <iostream>

Goal::Goal(float width, float height, float x, float y)
{
    rectangle.setSize({ width, height });

    if (!texture.loadFromFile("asset/Goal.png")) {
        std::cerr << "Erreur : Impossible de charger asset/Goal.png\n";
    }
    else {
        rectangle.setTexture(&texture);
    }

    rectangle.setPosition({ x, y });
}

void Goal::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}