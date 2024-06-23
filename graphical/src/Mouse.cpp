/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Mouse
*/

#include "Mouse.hpp"
#include <iostream>

Mouse::Mouse() {}

void Mouse::handleMouseScroll(sf::View& view, const sf::Event& event, Camera& camera)
{
    camera.handleZoom(view, event);
}

void Mouse::handleMouseMove(const sf::Vector2f& worldPos, std::vector<std::vector<Tile>>& tiles)
{
    for (auto& row : tiles) {
        for (auto& tile : row) {
            if (tile.contains(worldPos)) {
                tile.setHovered(true);
            } else {
                tile.setHovered(false);
            }
        }
    }
}

void Mouse::handleMouseClick(sf::RenderWindow& window, const sf::Vector2f& worldPos,
std::vector<std::vector<Tile>>& tiles, Tile*& selectedTile, const Character*& selectedCharacter,
Menu& menu, bool& tileSelected, bool& characterSelected, const std::vector<Resources>& resources,
const std::vector<Character>& characters, Client& client)
{
    Tile* newSelectedTile = nullptr;
    const Character* newSelectedCharacter = nullptr;

    for (auto& row : tiles) {
        for (auto& tile : row) {
            if (tile.contains(worldPos)) {
                newSelectedTile = &tile;
                break;
            }
        }
        if (newSelectedTile) break;
    }

    for (auto& character : characters) {
        if (character.contains(worldPos)) {
            newSelectedCharacter = &character;
            break;
        }
    }

    if (newSelectedTile && newSelectedTile != selectedTile) {
        if (selectedTile) {
            selectedTile->setSelected(false);
        }
        newSelectedTile->setSelected(true);
        selectedTile = newSelectedTile;
        tileSelected = true;
    } else if (!newSelectedTile && selectedTile) {
        selectedTile->setSelected(false);
        selectedTile = nullptr;
        tileSelected = false;
    }

    if (newSelectedCharacter && newSelectedCharacter != selectedCharacter) {
        selectedCharacter = newSelectedCharacter;
        characterSelected = true;
    } else if (!newSelectedCharacter) {
        selectedCharacter = nullptr;
        characterSelected = false;
    }

    if (characterSelected && selectedCharacter) {
        menu.updateCharacterText(selectedCharacter, characterSelected, characters, client);
    } else if (tileSelected && selectedTile) {
        menu.updateInfoText(selectedTile, tileSelected, resources, characters);
    }
}

void Mouse::handleAllMouseEvents(sf::RenderWindow& window, sf::View& view, const sf::Event& event,
std::vector<std::vector<Tile>>& tiles, Tile*& selectedTile, const Character*& selectedCharacter,
Menu& menu, bool& tileSelected, bool& characterSelected, Camera& camera, const std::vector<Resources>& resources,
const std::vector<Character>& characters, Client& client)
{
    sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);

    if (event.type == sf::Event::MouseWheelScrolled) {
        handleMouseScroll(view, event, camera);
    } else if (event.type == sf::Event::MouseMoved) {
        handleMouseMove(worldPos, tiles);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        handleMouseClick(window, worldPos, tiles, selectedTile, selectedCharacter, menu, tileSelected, characterSelected, resources, characters, client);
    }
}
