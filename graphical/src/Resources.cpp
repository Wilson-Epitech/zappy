/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Resources
*/

#include "../include/Resources.hpp"
#include <cstdlib>
#include <ctime>

const float Resources::animationSpeed = 0.2f;

Resources::Resources() {
    std::srand(static_cast<unsigned>(std::time(0)));
}

Resources::~Resources() {}

void Resources::setResources(const std::unordered_map<int, int>& resources, int x, int y, const std::unordered_map<int, sf::Texture*>& textures) {
    this->resources = resources;
    updateResourceSprites(x, y, textures);
}

void Resources::updateResourceSprites(int x, int y, const std::unordered_map<int, sf::Texture*>& textures) {
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

void Resources::drawResources(sf::RenderWindow &window) const {
    for (const auto& resourceSprite : resourceSprites) {
        window.draw(resourceSprite);
    }
}

void Resources::updateAnimation() {
    if (animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        for (size_t i = 0; i < resourceSprites.size(); ++i) {
            currentFrames[i] = (currentFrames[i] + 1) % frameCount;
            resourceSprites[i].setTextureRect(sf::IntRect(currentFrames[i] * frameWidth, 0, frameWidth, frameHeight));
        }
        animationClock.restart();
    }
}

const std::unordered_map<int, int>& Resources::getResources() const {
    return resources;
}
