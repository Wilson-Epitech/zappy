/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Tile
*/

#include "Tile.hpp"
#include <cstdlib>
#include <ctime>

const float squareSize = 100.0f;

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
}
