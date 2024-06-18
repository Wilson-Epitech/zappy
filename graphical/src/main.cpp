/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include "../include/Tile.h"
#include <vector>
#include <unordered_map>
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

void updateBoard(std::vector<std::vector<Tile>>& tiles) {
    for (auto& row : tiles) {
        for (auto& tile : row) {
            tile.updateAnimation();
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ZAPPY");
    std::srand(static_cast<unsigned>(std::time(0)));
    window.setFramerateLimit(30);
    sf::View view = window.getDefaultView();
    std::vector<std::vector<Tile>> tiles;

    sf::Texture groundTexture;
    groundTexture.loadFromFile("assets/tile.png");

    sf::Texture foodTexture;
    foodTexture.loadFromFile("assets/food.png");
    sf::Texture linemateTexture;
    linemateTexture.loadFromFile("assets/linemate.png");
    sf::Texture deraumereTexture;
    deraumereTexture.loadFromFile("assets/deraumere.png");
    sf::Texture siburTexture;
    siburTexture.loadFromFile("assets/sibur.png");
    sf::Texture mendianeTexture;
    mendianeTexture.loadFromFile("assets/mendiane.png");
    sf::Texture phirasTexture;
    phirasTexture.loadFromFile("assets/phiras.png");
    sf::Texture thystameTexture;
    thystameTexture.loadFromFile("assets/thystame.png");

    std::unordered_map<int, sf::Texture*> textures = {
        {0, &foodTexture},
        {1, &linemateTexture},
        {2, &deraumereTexture},
        {3, &siburTexture},
        {4, &mendianeTexture},
        {5, &phirasTexture},
        {6, &thystameTexture}
    };

    const int groundTileWidth = 32;
    const int groundTileHeight = 32;
    const int groundTileCount = 6;

    for (int row = 0; row < boardHeight; ++row) {
        std::vector<Tile> rowTiles;
        for (int col = 0; col < boardWidth; ++col) {
            int tileIndex = std::rand() % groundTileCount;
            sf::IntRect textureRect(tileIndex * groundTileWidth, 0, groundTileWidth, groundTileHeight);
            Tile tile(col, row, groundTexture, textureRect);
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

        /* Press A to randomly change the tiles ressources (will be replaced) */

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            std::unordered_map<int, int> newResources = {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}};
            for (int i = 0; i < boardWidth; i++)
                for (int j = 0; j < boardHeight; j++)
                    tiles[i][j].setResources(newResources, textures);
        }

        updateBoard(tiles);
        window.clear();
        window.setView(view);
        drawBoard(window, tiles);
        window.display();
    }
    return 0;
}
