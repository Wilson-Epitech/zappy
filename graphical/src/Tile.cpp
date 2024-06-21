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
const float Tile::animationSpeed = 0.2f;

Tile::Tile(int x, int y, sf::Texture& texture, const sf::IntRect& textureRect) : x(x), y(y) {
    sprite.setPosition(x * squareSize, y * squareSize);
    sprite.setScale(squareSize / textureRect.width, squareSize / textureRect.height);
    sprite.setTexture(texture);
    sprite.setTextureRect(textureRect);
    originalColor = sprite.getColor();
}

Tile::~Tile() {

}

void Tile::setSelected(bool selected) {
    this->selected = selected;
    if (selected) {
        sprite.setColor(sf::Color(
        originalColor.r + 200,
        originalColor.g + 200,
        originalColor.b + 200,
        originalColor.a));
    } else {
        sprite.setColor(originalColor);
    }
}

void Tile::setHovered(bool hovered) {
    if (hovered) {
        sprite.setColor(sf::Color(
            originalColor.r + 200,
            originalColor.g + 200,
            originalColor.b + 200,
            originalColor.a));
    } else if (!this->selected){
        sprite.setColor(originalColor);
    }
}

bool Tile::contains(const sf::Vector2f& point) const {
    return sprite.getGlobalBounds().contains(point);
}

void Tile::drawTile(sf::RenderWindow &window) const {
    window.draw(sprite);
    resources.drawResources(window);
    for (const auto& characterSprite : characterSprites) {
        window.draw(characterSprite);
    }
}

void Tile::setResources(const std::unordered_map<int, int>& resources, const std::unordered_map<int, sf::Texture*>& textures) {
    this->resources.setResources(resources, x, y, textures);
}

void Tile::setCharacters(const std::unordered_map<int, int>& characters, const std::unordered_map<int, sf::Texture*>& textures) {
    this->characters = characters;
    updateCharacterSprites(textures);
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
            float offsetX = static_cast<float>(std::rand() % static_cast<int>(squareSize - 40.0f));
            float offsetY = static_cast<float>(std::rand() % static_cast<int>(squareSize / 1.5 - 48.0f));
            characterSprite.setPosition(x * squareSize + offsetX, y * squareSize + offsetY);
            characterSprite.setTextureRect(sf::IntRect(0, 0, 16, 32));
            if (characterType == 10 && i == 0)
                characterSprite.setColor(sf::Color::Blue);
            else if (characterType == 11 && i == 0)
                characterSprite.setColor(sf::Color::Red);
            else if (characterType == 12 && i == 0) {
                characterSprite.setColor(sf::Color::Green);
            }
            characterSprites.push_back(characterSprite);
            characterFrames.push_back(0);
        }
    }
}

void Tile::updateAnimation() {
    resources.updateAnimation();
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
