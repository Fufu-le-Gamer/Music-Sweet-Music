#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "PlayerMove.h"
#include "LevelManager.h"
#include "Camera.h"
#include "Parallax.h"

int main()
{
    Player player(100.f, 100.f, 200.f, 26000.f);
	PlayerMove movement;
	LevelManager levelManager;
	levelManager.loadBiome("Game.txt");

	std::vector<sf::RectangleShape> platforms;
	for (const auto& p : levelManager.getPlatforms()) {
		platforms.push_back(p.getShape());
	}

	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Music Sweet Music");
	window.setFramerateLimit(60);
	sf::Clock clock;

	Camera camera(800.f, 600.f);
	Parallax parallax;
    parallax.setWindowSize({ 800.f, 600.f });
    parallax.addLayer("BG/BG1.png", 0.1f, 0.f, 0.f, 1.0f);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();

		player.updateAnimation(dt);
        movement.update(player, platforms, dt);

        camera.update(player.getPosX(), player.getPosY());

        window.clear();

        window.setView(window.getDefaultView());
        parallax.update({ player.getPosX(), player.getPosY() });
        parallax.draw(window);

        window.setView(camera.getView());
        for (const auto& plat : levelManager.getPlatforms())
            window.draw(plat.getShape());
        player.draw(window);

        window.display();
    }
}




