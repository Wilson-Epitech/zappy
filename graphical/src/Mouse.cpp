/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Mouse
*/

#include "Mouse.hpp"

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

void Mouse::handleMouseClick(sf::RenderWindow& window, const sf::Vector2f& worldPos, std::vector<std::vector<Tile>>& tiles, Tile*& selectedTile, Menu& menu, bool& tileSelected, const std::vector<Resources>& resources, const std::vector<Character>& characters) {
    Tile* newSelectedTile = nullptr;

    for (auto& row : tiles) {
        for (auto& tile : row) {
            if (tile.contains(worldPos)) {
                newSelectedTile = &tile;
                break;
            }
        }
        if (newSelectedTile) break;
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

    menu.updateInfoText(selectedTile, tileSelected, resources, characters);
}

void Mouse::handleAllMouseEvents(sf::RenderWindow& window, sf::View& view, const sf::Event& event, std::vector<std::vector<Tile>>& tiles, Tile*& selectedTile, Menu& menu, bool& tileSelected, Camera& camera, const std::vector<Resources>& resources, const std::vector<Character>& characters) {
    sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);

    if (event.type == sf::Event::MouseWheelScrolled) {
        handleMouseScroll(view, event, camera);
    } else if (event.type == sf::Event::MouseMoved) {
        handleMouseMove(worldPos, tiles);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        handleMouseClick(window, worldPos, tiles, selectedTile, menu, tileSelected, resources, characters);
    }
}
