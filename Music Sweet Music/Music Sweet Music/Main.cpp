#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
	Player player(100.f, 100.f, 200.f, 200.f);
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Music Sweet Music");

	while (window.isOpen())
	{
		while (const auto event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		window.clear();
		player.draw(window);
		window.display();
	}
}




