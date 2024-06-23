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
#include "Character.hpp"
#include "Client.hpp"

class Menu {
public:
    Menu(const sf::Vector2u& windowSize);

    void updateInfoText(const Tile* selectedTile, bool tileSelected, const std::vector<Resources>& resources, const std::vector<Character>& characters);
    void updateCharacterText(const Character* selectedCharacter, bool characterSelected, const std::vector<Character>& characters, Client& client);
    void draw(sf::RenderWindow& window, bool tileSelected, bool characterSelected) const;

private:
    sf::Font font;
    sf::Text infoText;
    sf::Text characterText;
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
