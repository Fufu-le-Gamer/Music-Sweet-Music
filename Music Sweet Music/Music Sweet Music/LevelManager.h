#pragma once
#include "Platforms.h"
#include <vector>
#include <string>

class LevelManager
{
public:
    void loadBiome(const std::string& filename);
    void draw(sf::RenderWindow& window) const;
    const std::vector<Platforms>& getPlatforms() const { return m_platforms; }

private:
    std::vector<Platforms> m_platforms;
};
