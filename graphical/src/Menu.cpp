/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Menu
*/

#include "Menu.hpp"
#include <sstream>

Menu::Menu(const sf::Vector2u& windowSize) {
    font.loadFromFile("assets/font.ttf");
    infoText.setFont(font);
    infoText.setCharacterSize(30);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition(10, windowSize.y - 150);

    infoRect.setSize(sf::Vector2f(windowSize.x, 150));
    infoRect.setFillColor(sf::Color(0, 0, 0, 150));
    infoRect.setPosition(0, windowSize.y - 150);
}

void Menu::updateInfoText(const Tile* selectedTile, bool tileSelected, const std::vector<Resources>& resources, const std::vector<Character>& characters) {
    if (tileSelected && selectedTile) {
        std::ostringstream oss;

        int characterCount = 0;
        for (const auto& character : characters) {
            if (character.getPosX() == selectedTile->getX() && character.getPosY() == selectedTile->getY()) {
                ++characterCount;
            }
        }

        oss << "Tile Position : [ " << selectedTile->getX() << " ,  " << selectedTile->getY() << " ]\tCharacters : " << characterCount << "\n";

        for (const auto& resource : resources) {
            if (resource.getX() == selectedTile->getX() && resource.getY() == selectedTile->getY()) {
                oss << "Resources :\n";
                oss << "Food : " << resource.getFood() << "\t";
                oss << "Linemate : " << resource.getLinemate() << "\t";
                oss << "Deraumere : " << resource.getDeraumere() << "\t";
                oss << "Sibur : " << resource.getSibur() << "\t";
                oss << "Mendiane : " << resource.getMendiane() << "\t";
                oss << "Phiras : " << resource.getPhiras() << "\t";
                oss << "Thystame : " << resource.getThystame() << "\t";
                break;
            }
        }

        infoText.setString(oss.str());
    } else {
        infoText.setString("");
    }
}


void Menu::draw(sf::RenderWindow& window, bool tileSelected) const {
    if (tileSelected) {
        window.draw(infoRect);
        window.draw(infoText);
    }
}
