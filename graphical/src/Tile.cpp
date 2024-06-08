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
const float resourceSize = 20.0f;

Tile::Tile(int x, int y, sf::Texture& texture) : x(x), y(y) {
    sprite.setPosition(x * squareSize, y * squareSize);
    sprite.setScale(squareSize / texture.getSize().x, squareSize / texture.getSize().y);
    sprite.setTexture(texture);
}

Tile::~Tile() {

}

void Tile::drawTile(sf::RenderWindow &window) const {
    window.draw(sprite);
    for (const auto& resourceSprite : resourceSprites) {
        window.draw(resourceSprite);
    }
}

void Tile::setResources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame) {
    this->food = food;
    this->linemate = linemate;
    this->deraumere = deraumere;
    this->sibur = sibur;
    this->mendiane = mendiane;
    this->phiras = phiras;
    this->thystame = thystame;
}

void Tile::addResourceSprite(sf::Texture& resourceTexture, int count) {
    for (int i = 0; i < count; ++i) {
        sf::Sprite resourceSprite;
        resourceSprite.setTexture(resourceTexture);
        resourceSprite.setScale(resourceSize / resourceTexture.getSize().x, resourceSize / resourceTexture.getSize().y);
        float offsetX = static_cast<float>(std::rand() % static_cast<int>(squareSize - resourceSize));
        float offsetY = static_cast<float>(std::rand() % static_cast<int>(squareSize - resourceSize));
        resourceSprite.setPosition(x * squareSize + offsetX, y * squareSize + offsetY);
        resourceSprites.push_back(resourceSprite);
    }
}
