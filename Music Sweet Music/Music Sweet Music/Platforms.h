#pragma once
#include <SFML/Graphics.hpp>

class Platforms
{
public:
	Platforms(const sf::Vector2f& size, const sf::Vector2f& position);
	void draw(sf::RenderWindow& window) const;
	const sf::FloatRect getBounds() const { return m_shape.getGlobalBounds(); }
	const sf::RectangleShape& getShape() const { return m_shape; }

private:
	sf::RectangleShape m_shape;
};

