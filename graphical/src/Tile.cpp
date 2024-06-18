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
    for (const auto& characterSprite : characterSprites) {
        window.draw(characterSprite);
    }
}

void Tile::setResources(const std::unordered_map<int, int>& resources, const std::unordered_map<int, sf::Texture*>& textures) {
    this->resources = resources;
    updateResourceSprites(textures);
}

void Tile::setCharacters(const std::unordered_map<int, int>& characters, const std::unordered_map<int, sf::Texture*>& textures) {
    this->characters = characters;
    updateCharacterSprites(textures);
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

void Tile::updateCharacterSprites(const std::unordered_map<int, sf::Texture*>& textures) {
    characterSprites.clear();

    for (const auto& pair : characters) {
        int characterType = pair.first;
        int count = pair.second;
        for (int i = 0; i < count; ++i) {
            sf::Sprite characterSprite;
            characterSprite.setTexture(*textures.at(characterType));
            characterSprite.setScale(squareSize / 48.0f, squareSize / 32.0f);
            sf::IntRect textureRect(0, 0, 16, 32);
            characterSprite.setTextureRect(textureRect);
            characterSprite.setPosition(x * squareSize + 35, y * squareSize);
            characterSprites.push_back(characterSprite);
            characterFrames.push_back(0);
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

void Tile::updateCharacterAnimation() {
    if (characterClock.getElapsedTime().asSeconds() > animationSpeed) {
        for (size_t i = 0; i < characterSprites.size(); ++i) {
            characterFrames[i] = (characterFrames[i] + 1) % 3;
            characterSprites[i].setTextureRect(sf::IntRect(characterFrames[i] * 16, 0, 16, 32));
        }
        characterClock.restart();
    }
}