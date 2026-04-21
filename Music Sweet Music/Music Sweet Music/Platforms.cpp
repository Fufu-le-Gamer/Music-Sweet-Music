#include "Platforms.h"

Platforms::Platforms(const sf::Vector2f& size, const sf::Vector2f& position)
{
    m_shape.setSize(size);
    m_shape.setPosition(position);
    m_shape.setFillColor(sf::Color(255, 0, 0, 0.5));
    m_shape.setOutlineColor(sf::Color(255,0, 0, 0.5));
    m_shape.setOutlineThickness(1.f);
}

void Platforms::draw(sf::RenderWindow& window) const
{
    window.draw(m_shape);
}
