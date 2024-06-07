/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Tile
*/

#include "../include/Tile.h"

const float squareSize = 100.0f;

Tile::Tile(int x, int y) : x(x), y(y) {
    square.setSize(sf::Vector2f(squareSize, squareSize));
    square.setPosition(x * squareSize, y * squareSize);
    if ((x + y) % 2 == 0) {
        square.setFillColor(sf::Color::White);
    } else {
        square.setFillColor(sf::Color::Black);
    }
}

Tile::~Tile() {

}

void Tile::drawTile(sf::RenderWindow &window) const{
    window.draw(square);
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
