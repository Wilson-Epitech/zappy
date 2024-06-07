/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Tile
*/

#include "../include/Tile.h"

const float squareSize = 100.0f;

Tile::Tile(int x, int y, sf::Texture& texture) : x(x), y(y) {
    sprite.setPosition(x * squareSize, y * squareSize);
    sprite.setScale(squareSize / texture.getSize().x, squareSize / texture.getSize().y);
    sprite.setTexture(texture);
}

Tile::~Tile() {

}

void Tile::drawTile(sf::RenderWindow &window) const{
    window.draw(sprite);
}

void Tile::getResources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame) {
    this->food = food;
    this->linemate = linemate;
    this->deraumere = deraumere;
    this->sibur = sibur;
    this->mendiane = mendiane;
    this->phiras = phiras;
    this->thystame = thystame;
}
