#include "Player.h"

Player::Player(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 100.f, 100.f });
    texture = sf::Texture("asset/Player.png");
    rectangle.setTexture(&texture);

    setPosition(x, y);
}

void Player::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({ {0, 0}, {50, 30} });
}

void Player::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}