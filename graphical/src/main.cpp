/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include "../include/Tile.h"
#include <vector>
#include <cstdlib>
#include <ctime>

const int boardWidth = 10;
const int boardHeight = 10;
const float moveSpeed = 10.0f;
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
    std::srand(static_cast<unsigned>(std::time(0)));
    window.setFramerateLimit(30);
    sf::View view = window.getDefaultView();
    std::vector<std::vector<Tile>> tiles;

    sf::Texture tileLight;
    tileLight.loadFromFile("assets/tile.jpeg");
    sf::Texture tileDark;
    tileDark.loadFromFile("assets/yard.jpeg");

    sf::Texture foodTexture;
    foodTexture.loadFromFile("assets/food.png");
    sf::Texture linemateTexture;
    linemateTexture.loadFromFile("assets/food.png");
    sf::Texture deraumereTexture;
    deraumereTexture.loadFromFile("assets/food.png");
    sf::Texture siburTexture;
    siburTexture.loadFromFile("assets/food.png");
    sf::Texture mendianeTexture;
    mendianeTexture.loadFromFile("assets/food.png");
    sf::Texture phirasTexture;
    phirasTexture.loadFromFile("assets/food.png");
    sf::Texture thystameTexture;
    thystameTexture.loadFromFile("assets/food.png");

    for (int row = 0; row < boardHeight; ++row) {
        std::vector<Tile> rowTiles;
        for (int col = 0; col < boardWidth; ++col) {
            Tile tile(col, row, (row + col) % 2 ? tileLight : tileDark);
            tile.setResources(1, 1, 1, 1, 1, 1, 1);
            tile.addResourceSprite(foodTexture, 1);
            tile.addResourceSprite(linemateTexture, 1);
            tile.addResourceSprite(deraumereTexture, 1);
            tile.addResourceSprite(siburTexture, 1);
            tile.addResourceSprite(mendianeTexture, 1);
            tile.addResourceSprite(phirasTexture, 1);
            tile.addResourceSprite(thystameTexture, 1);
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
