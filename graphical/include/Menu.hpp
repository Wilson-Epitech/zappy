/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Graphics.hpp>
#include "Tile.hpp"

class Menu {
public:
    Menu(const sf::Vector2u& windowSize);

    void updateInfoText(const Tile* selectedTile, bool tileSelected);
    void draw(sf::RenderWindow& window, bool tileSelected) const;

private:
    sf::Font font;
    sf::Text infoText;
    sf::RectangleShape infoRect;

    std::unordered_map<int, std::string> textureNames = {
        {0, "Food"},
        {1, "Linemate"},
        {2, "Deraumere"},
        {3, "Sibur"},
        {4, "Mendiane"},
        {5, "Phiras"},
        {6, "Thystame"}
    };
};

#endif /* !MENU_HPP_ */
