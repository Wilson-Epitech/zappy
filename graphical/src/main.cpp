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
            tile.updateCharacterAnimation();
        }
    }
}

void handleMouseClick(sf::RenderWindow& window, std::vector<std::vector<Tile>>& tiles, const sf::Vector2i& mousePos) {
    for (auto& row : tiles) {
        for (auto& tile : row) {
            if (tile.contains(window.mapPixelToCoords(mousePos))) {
                for (auto& otherRow : tiles) {
                    for (auto& otherTile : otherRow) {
                        if (&otherTile != &tile) {
                            otherTile.setSelected(false);
                        }
                    }
                }
                tile.setSelected(true);
                return;
            }
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

    sf::Texture character1Texture;
    character1Texture.loadFromFile("assets/mage.png");
    sf::Texture character2Texture;
    character2Texture.loadFromFile("assets/mage.png");
    sf::Texture character3Texture;
    character3Texture.loadFromFile("assets/mage.png");

    std::unordered_map<int, sf::Texture*> textures = {
        {0, &foodTexture},
        {1, &linemateTexture},
        {2, &deraumereTexture},
        {3, &siburTexture},
        {4, &mendianeTexture},
        {5, &phirasTexture},
        {6, &thystameTexture},
        {10, &character1Texture},
        {11, &character2Texture},
        {12, &character3Texture},
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
            else if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
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
            else if (event.type = sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left) {
                        handleMouseClick(window, tiles, sf::Mouse::getPosition(window));
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

        /* Press C to add characters (will be replaced) */

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            std::unordered_map<int, int> newCharacters = {{10, 1}, {11, 1}, {12, 1}};
            tiles[5][5].setCharacters(newCharacters, textures);
            tiles[0][3].setCharacters(newCharacters, textures);
        }

        updateBoard(tiles);
        window.clear();
        window.setView(view);
        drawBoard(window, tiles);
        window.display();
    }
    return 0;
}
