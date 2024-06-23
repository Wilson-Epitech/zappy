/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Mouse
*/

#include "Mouse.hpp"
#include <iostream>
#include "Client.hpp"

/**
    * @brief Constructor for the Mouse class.
*/
Mouse::Mouse() {}

/**
 * @brief Handles the mouse scroll event.
 * @param view The view to zoom.
 * @param event The event to handle.
 * @param camera The camera to update.
*/
void Mouse::handleMouseScroll(sf::View& view, const sf::Event& event, Camera& camera)
{
    camera.handleZoom(view, event);
}

/**
 * @brief Handles the mouse move event.
 * @param worldPos The position of the mouse in the world.
 * @param tiles The tiles to update.
*/
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

/**
 * @brief Handles the mouse click event.
 * @param window The window to draw on.
 * @param worldPos The position of the mouse in
 * the world.
 * @param tiles The tiles to update.
 * @param selectedTile The selected tile.
 * @param selectedCharacter The selected
 * character.
 * @param menu The menu to update.
 * @param tileSelected The tile selected.
 * @param characterSelected The character
 * selected.
 * @param resources The resources to update.
 * @param characters The characters to update.
 * @param client The client to send commands.
*/
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
            std::string command_pin = "pin " + std::to_string(character.getId());
            std::string command_plv = "plv " + std::to_string(character.getId());
            client.send(command_pin);
            client.send(command_plv);
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

/**
 * @brief Handles all mouse events.
 * @param window The window to draw on.
 * @param view The view to update.
 * @param event The event to handle.
 * @param tiles The tiles to update.
 * @param selectedTile The selected tile.
 * @param selectedCharacter The selected character.
 * @param menu The menu to update.
 * @param tileSelected The tile selected.
 * @param characterSelected The character selected.
 * @param camera The camera to update.
 * @param resources The resources to update.
 * @param characters The characters to update.
 * @param client The client to send commands.
*/
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
