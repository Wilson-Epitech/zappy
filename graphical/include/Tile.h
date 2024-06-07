/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Tile
*/

#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>

class Tile {
public:
    Tile(int x, int y);
    ~Tile();

    void drawTile(sf::RenderWindow &window) const;
    void getResources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);

private:
    sf::RectangleShape square;
    int x, y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
};

#endif /* TILE_H_ */
