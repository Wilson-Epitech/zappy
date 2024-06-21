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

void Menu::updateInfoText(const Tile* selectedTile, bool tileSelected) {
    if (tileSelected && selectedTile) {
        std::ostringstream oss;
        oss << "Tile Position: (" << selectedTile->getX() << ", " << selectedTile->getY() << ")\t\t\t";
        const auto& resources = selectedTile->getResources();
        const auto& characters = selectedTile->getCharacters();
        int totalCharacters = 0;
        for (const auto& pair : characters) {
            totalCharacters += pair.second;
        }
        oss << "Total Characters: " << totalCharacters << "\n\n";
        oss << "Resources:\n";
        for (const auto& pair : resources) {
            int resourceId = pair.first;
            int quantity = pair.second;
            if (textureNames.find(resourceId) != textureNames.end()) {
                oss << textureNames[resourceId] << ": " << quantity << "\t\t";
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
