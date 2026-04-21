#include "Player.h"

Player::Player(float width, float height, float x, float y)
{
    rectangle.setSize({ width, height });

    if (!texture.loadFromFile("asset/spritsheet.png")) {
        std::cerr << "Erreur de chargement !\n";
    }

    rectangle.setTexture(&texture);
    frameRect = sf::IntRect({ 0, 0 }, { 64, 64 });
    rectangle.setTextureRect(frameRect);
    rectangle.setPosition({ x, y });
}

void Player::updateAnimation(float dt)
{
    timer += dt;
    if (timer >= frameTime)
    {
        timer = 0.f;
        currentFrame++;

        if (currentFrame >= maxFrames)
            currentFrame = 0;

        frameRect.position.x = currentFrame * frameRect.size.x;

        rectangle.setTextureRect(frameRect);
    }
}

void Player::setDirection(int row)
{
    frameRect.position.y = row * frameRect.size.y;
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}