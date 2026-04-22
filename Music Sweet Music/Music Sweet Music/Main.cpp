#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "PlayerMove.h"
#include "LevelManager.h"
#include "Camera.h"
#include "Parallax.h"
#include "Scene.h"
#include "Play.h"
#include "Background.h"
#include "Goal.h"
#include "Ennemi.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Music Sweet Music");
	window.setFramerateLimit(60);
	sf::Clock clock;

    Player player(100.f, 100.f, 200.f, 27400.f);
	Goal goal(100.f, 100.f, 5000.f, 27400.f);
	Ennemi ennemi(100.f, 100.f, 1000.f, 27400.f);
	PlayerMove movement;
	LevelManager levelManager;
	levelManager.loadBiome("Game.txt");

	std::vector<sf::RectangleShape> platforms;
	for (const auto& p : levelManager.getPlatforms()) {
		platforms.push_back(p.getShape());
	}

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
		ennemi.update(dt);

        camera.update(player.getPosX(), player.getPosY());

        if (player.rectangle.getGlobalBounds().findIntersection(goal.rectangle.getGlobalBounds()))
        {
            std::cout << "Niveau Termine ! Victoire !" << std::endl;
            window.close();
        }

        if (player.rectangle.getGlobalBounds().findIntersection(ennemi.rectangle.getGlobalBounds()))
        {
            std::cout << "Aie ! Retour au debut !" << std::endl;
            player.rectangle.setPosition({ 50.f, 26000.f });
        }

        window.clear();

        window.setView(window.getDefaultView());
        parallax.update({ player.getPosX(), player.getPosY() });
        parallax.draw(window);

        window.setView(camera.getView());
        for (const auto& plat : levelManager.getPlatforms())
            window.draw(plat.getShape());

		goal.draw(window);
		ennemi.draw(window);
        player.draw(window);

        window.display();
    }
	return 0;
}




