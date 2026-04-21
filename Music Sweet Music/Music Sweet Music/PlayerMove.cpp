#include "PlayerMove.h"

PlayerMove::PlayerMove()
    : velocity(0.f, 0.f), onGround(false), jumpCount(0)
{

}

PlayerMove& PlayerMove::operator=(const PlayerMove& Other)
{
    velocity = Other.velocity;
    onGround = Other.onGround;
    jumpCount = Other.jumpCount;
    return *this;
}

void PlayerMove::update(Player& p, const std::vector<sf::RectangleShape>& platforms, float dt)
{
    bool pressingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Q);

    bool pressingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D);

    bool pressingJump = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Z);

    velocity.x = 0.f;

    // Gestion des directions et des animations
    if (pressingLeft) {
        velocity.x = -speed;
        p.setDirection(39); // Met la ligne 2 (exemple pour marche à gauche)
    }
    else if (pressingRight) {
        velocity.x = speed;
        p.setDirection(41); // Met la ligne 1 (exemple pour marche à droite)
    }
    else {
        p.setDirection(25); // Met la ligne 0 (repos / idle)
    }

    if (pressingJump && onGround)
    {
        velocity.y = jumpForce;
        onGround = false;
        p.setDirection(29);
    }

    // --- Mouvement horizontal ---
    p.rectangle.move({ velocity.x * dt, 0.f });

    // --- Mouvement vertical ---
    velocity.y += gravity * dt;
    // Cap de vitesse pour éviter de traverser le sol
    if (velocity.y > fallSpeed) velocity.y = fallSpeed;

    p.rectangle.move({ 0.f, velocity.y * dt });

    onGround = false;

    // --- Collisions ---
    for (const auto& plat : platforms)
    {
        auto inter = p.rectangle.getGlobalBounds().findIntersection(plat.getGlobalBounds());
        if (inter)
        {
            if (velocity.y > 0.f) // Tombe
            {
                p.rectangle.move({ 0.f, -inter->size.y });
                onGround = true;
            }
            else if (velocity.y < 0.f) // Cogne la tête
            {
                p.rectangle.move({ 0.f, inter->size.y });
            }
            velocity.y = 0.f;
        }
    }
}
