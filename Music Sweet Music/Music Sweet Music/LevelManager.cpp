#include "LevelManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

void LevelManager::loadBiome(const std::string& filename)
{
    m_platforms.clear();
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir : " << filename << "\n";
        return;
    }

    std::string line;
    bool inPlatformsSection = false;
	const float verticalOffset = 500.f; // Adjust this value as needed

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        if (line.find("PLATFORMS") != std::string::npos) {
            inPlatformsSection = true;
            continue;
        }

        if (inPlatformsSection) {
            std::istringstream iss(line);
            float x, y, width, height;
            if (iss >> x >> y >> width >> height) {
                sf::Vector2f size(width, height);
                sf::Vector2f position(x, y + verticalOffset);

                m_platforms.emplace_back(size, position);
            }
        }
    }
}

void LevelManager::draw(sf::RenderWindow& window) const
{
    for (const auto& p : m_platforms)
        p.draw(window);
}
