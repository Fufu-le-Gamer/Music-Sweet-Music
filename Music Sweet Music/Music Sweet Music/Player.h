#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
    sf::Texture texture;
    sf::IntRect frameRect; // Le rectangle de découpe

    // Paramètres d'animation
    int currentFrame = 0;
    int maxFrames = 5;      // Nombre d'images sur une ligne
    float frameTime = 0.1f; // Temps entre chaque image
    float timer = 0.f;

public:
    Player(float width, float height, float x, float y); // Simplifié : la taille est gérée par la frame

    void updateAnimation(float dt);
    void setDirection(int row); // Pour changer de ligne (ex: 0=repos, 1=course)

    void draw(sf::RenderWindow& window);

    float getPosX() const { return rectangle.getPosition().x; }
    float getPosY() const { return rectangle.getPosition().y; }
    float getHeight() const { return rectangle.getSize().y; }

    sf::RectangleShape rectangle;
};
