/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Menu
*/

#include "Menu.hpp"
#include <sstream>
#include "client.hpp"

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

        oss << "Tile Position : ( " << selectedTile->getX() << " ,  " << selectedTile->getY() << " )\tCharacters : " << characterCount << "\n";

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

void Menu::updateCharacterText(const Character* selectedCharacter, bool characterSelected, const std::vector<Character>& characters, Client& client) {
    if (characterSelected && selectedCharacter) {
        std::ostringstream oss;

        oss << "Character ID : " << selectedCharacter->getId() << "\t";
        oss << "Position : ( " << selectedCharacter->getPosX() << " ,  " << selectedCharacter->getPosY() << " )\t";
        oss << "Level : " << client.getPinLv() << "\t";
        oss << "Team : " << selectedCharacter->getTeam() << "\n";

        oss << "Inventory :\n";
        oss << "Food : " << client.getPinFood() << "\t";
        oss << "Linemate : " << client.getPinLinemate() << "\t";
        oss << "Deraumere : " << client.getPinDeraumere() << "\t";
        oss << "Sibur : " << client.getPinSibur() << "\t";
        oss << "Mendiane : " << client.getPinMendiane() << "\t";
        oss << "Phiras : " << client.getPinPhiras() << "\t";
        oss << "Thystame : " << client.getPinThystame() << "\n";

        infoText.setString(oss.str());
    } else {
        infoText.setString("");
    }
}


void Menu::draw(sf::RenderWindow& window, bool tileSelected, bool characterSelected) const {
    if (tileSelected || characterSelected) {
        window.draw(infoRect);
        window.draw(infoText);
    }
}
