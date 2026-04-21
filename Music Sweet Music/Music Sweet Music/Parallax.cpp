#include "Parallax.h"

ParallaxLayer::ParallaxLayer(const std::string& texturePath, float factor, float scale)
    : factor(factor), scale(scale)
{
    if (texture.loadFromFile(texturePath))
    {
        texture.setRepeated(true);
    }
}

void Parallax::setWindowSize(const sf::Vector2f& windowSize)
{
    m_windowSize = windowSize;
}

bool Parallax::addLayer(const std::string& texturePath, float factor, float baseX, float baseY, float scale)
{
    m_layers.emplace_back(texturePath, factor, scale);

    auto& layer = m_layers.back();
    layer.baseX = baseX;
    layer.baseY = baseY;

    if (layer.texture.getSize().x > 0)
        layer.rect.setTexture(&layer.texture);

    return layer.texture.getSize().x > 0;
}

void Parallax::update(const sf::Vector2f& referencePos)
{
    if (m_windowSize.x <= 0.f || m_windowSize.y <= 0.f)
        return;

    for (auto& layer : m_layers)
    {
        if(layer.texture.getSize().x <= 0)
			continue;

        float offsetX = referencePos.x * layer.factor;
        float offsetY = referencePos.y * (layer.factor * 0.1f);

		layer.rect.setSize(m_windowSize);
        layer.rect.setPosition({ layer.baseX, layer.baseY });

        sf::Vector2i textureOffset{ static_cast<int>(offsetX), static_cast<int>(offsetY) };
        sf::Vector2i textureSize{
            static_cast<int>(m_windowSize.x / layer.scale),
            static_cast<int>(m_windowSize.y / layer.scale)
        };
        layer.rect.setTextureRect(sf::IntRect(textureOffset, textureSize));
    }
}
void Parallax::draw(sf::RenderWindow& window) const
{
    for (const auto& layer : m_layers)
    {
        if (layer.rect.getTexture() || layer.rect.getFillColor() != sf::Color::Transparent)
            window.draw(layer.rect);
    }
}
