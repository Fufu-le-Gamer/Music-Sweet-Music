#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Music Sweet Music");

	while (window.isOpen())
	{
		while (const auto event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		window.clear();
		window.display();
	}
}




