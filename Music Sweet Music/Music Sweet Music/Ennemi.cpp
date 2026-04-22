#include "Ennemi.h"

Ennemi::Ennemi(float width, float height, float x, float y)
{
    rectangle.setSize({ width, height });
    rectangle.setPosition({ x, y });

    if (!texture.loadFromFile("asset/spritsheetE.png")) {
        std::cerr << "Erreur de chargement de spritsheetE.png\n";
        rectangle.setFillColor(sf::Color::Red);
    }
    else {
        rectangle.setTexture(&texture);
    }

    // On choisit une ligne (par exemple la 2ème ligne : Y = 48)
    // Et on définit la taille d'une cellule de sprite (ex: 48x48)
    frameRect = sf::IntRect({ 0, 1475 }, { 64, 64 });
    rectangle.setTextureRect(frameRect);
}

void Ennemi::update(float dt)
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

void Ennemi::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}