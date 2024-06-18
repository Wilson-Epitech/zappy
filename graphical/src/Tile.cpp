/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Tile
*/

#include "../include/Tile.h"
#include <cstdlib>
#include <ctime>

const float squareSize = 100.0f;
const float resourceSize = 15.0f;
const float Tile::animationSpeed = 0.2f;

Tile::Tile(int x, int y, sf::Texture& texture, const sf::IntRect& textureRect) : x(x), y(y) {
    sprite.setPosition(x * squareSize, y * squareSize);
    sprite.setScale(squareSize / textureRect.width, squareSize / textureRect.height);
    sprite.setTexture(texture);
    sprite.setTextureRect(textureRect);
}

Tile::~Tile() {

}

void Tile::drawTile(sf::RenderWindow &window) const {
    window.draw(sprite);
    for (const auto& resourceSprite : resourceSprites) {
        window.draw(resourceSprite);
    }
}

void Tile::setResources(const std::unordered_map<int, int>& resources, const std::unordered_map<int, sf::Texture*>& textures) {
    this->resources = resources;
    updateResourceSprites(textures);
}

void Tile::updateResourceSprites(const std::unordered_map<int, sf::Texture*>& textures) {
    resourceSprites.clear();
    currentFrames.clear();

    for (const auto& pair : resources) {
        int resourceType = pair.first;
        int count = pair.second;
        for (int i = 0; i < count; ++i) {
            sf::Sprite resourceSprite;
            resourceSprite.setTexture(*textures.at(resourceType));
            resourceSprite.setScale(resourceSize / frameWidth, resourceSize / frameHeight);
            float offsetX = static_cast<float>(std::rand() % static_cast<int>(squareSize - resourceSize));
            float offsetY = static_cast<float>(std::rand() % static_cast<int>(squareSize / 1.5 - resourceSize));
            resourceSprite.setPosition(x * squareSize + offsetX, y * squareSize + offsetY);
            resourceSprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
            resourceSprites.push_back(resourceSprite);
            currentFrames.push_back(0);
        }
    }
}

void Tile::updateAnimation() {
    if (animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        for (size_t i = 0; i < resourceSprites.size(); ++i) {
            currentFrames[i] = (currentFrames[i] + 1) % frameCount;
            resourceSprites[i].setTextureRect(sf::IntRect(currentFrames[i] * frameWidth, 0, frameWidth, frameHeight));
        }
        animationClock.restart();
    }
}
