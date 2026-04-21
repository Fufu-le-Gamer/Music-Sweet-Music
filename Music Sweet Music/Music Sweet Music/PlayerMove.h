#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>

class PlayerMove
{
public:
    sf::Vector2f velocity;
    bool         onGround;
    int          jumpCount;

    const float gravity = 2000.f;
    const float speed = 600.f;
    const float jumpForce = -900.f;
    const float fallSpeed = 1500.f;
    const int   maxJumps = 1;

    PlayerMove();
    PlayerMove& operator=(const PlayerMove& Other);
    void update(Player& p, const std::vector<sf::RectangleShape>& platforms, float dt);
};
