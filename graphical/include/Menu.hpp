#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "Tile.h"

class Menu {
public:
    Menu(const sf::Vector2u& windowSize);

    void updateInfoText(const Tile* selectedTile, bool tileSelected);
    void draw(sf::RenderWindow& window, bool tileSelected) const;

private:
    sf::Font font;
    sf::Text infoText;
    sf::RectangleShape infoRect;
};

#endif // MENU_HPP
