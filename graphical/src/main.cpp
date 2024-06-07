/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include "../include/Tile.h"
#include <vector>

const float squareSize = 100.0f;
const int boardWidth = 10;
const int boardHeight = 10;
const float moveSpeed = 1.0f;
const float zoomCam = 1.1f;

void drawBoard(sf::RenderWindow& window, const std::vector<std::vector<Tile>>& tiles) {
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            tile.drawTile(window);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "ZAPPY");
    sf::View view = window.getDefaultView();
    std::vector<std::vector<Tile>> tiles;

    for (int row = 0; row < boardHeight; ++row) {
        std::vector<Tile> rowTiles;
        for (int col = 0; col < boardWidth; ++col) {
            Tile tile(col, row);
            tile.getResources(1, 1, 1, 1, 1, 1 ,1);
            rowTiles.push_back(tile);
        }
        tiles.push_back(rowTiles);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0) {
                    view.zoom(1.0f / zoomCam);
                } else if (event.mouseWheelScroll.delta < 0) {
                    view.zoom(zoomCam);
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            view.move(0, -moveSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            view.move(0, moveSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            view.move(-moveSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            view.move(moveSpeed, 0);
        }
        window.clear();
        window.setView(view);
        drawBoard(window, tiles);
        window.display();
    }
    return 0;
}
