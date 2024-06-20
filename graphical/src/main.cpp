#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/Tile.h"
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "../include/client.hpp"


const int boardWidth = 10;
const int boardHeight = 10;
const float moveSpeed = 10.0f;
const float zoomCam = 1.1f;

// void moveParallax(sf::Sprite& layer, float moveSpeed, sf::Vector2f direction) {
//     layer.move(direction * moveSpeed);
//     if (layer.getPosition().x < -layer.getGlobalBounds().width) {
//         layer.setPosition(layer.getPosition().x + layer.getGlobalBounds().width * 2, layer.getPosition().y);
//     }
//     if (layer.getPosition().x > layer.getGlobalBounds().width) {
//         layer.setPosition(layer.getPosition().x - layer.getGlobalBounds().width * 2, layer.getPosition().y);
//     }
// }

// void drawBoard(sf::RenderWindow& window, const std::vector<std::vector<Tile>>& tiles) {
//     for (const auto& row : tiles) {
//         for (const auto& tile : row) {
//             tile.drawTile(window);
//         }
//     }
// }

// void updateBoard(std::vector<std::vector<Tile>>& tiles) {
//     for (auto& row : tiles) {
//         for (auto& tile : row) {
//             tile.updateAnimation();
//             tile.updateCharacterAnimation();
//         }
//     }
// }

// void handleMouseClick(sf::RenderWindow& window, std::vector<std::vector<Tile>>& tiles, const sf::Vector2i& mousePos, bool& tileSelected, sf::Text& infoText, const std::unordered_map<int, sf::Texture*>& textures) {
//     for (auto& row : tiles) {
//         for (auto& tile : row) {
//             if (tile.contains(window.mapPixelToCoords(mousePos))) {
//                 for (auto& otherRow : tiles) {
//                     for (auto& otherTile : otherRow) {
//                         if (&otherTile != &tile) {
//                             otherTile.setSelected(false);
//                         }
//                     }
//                 }
//                 tile.setSelected(true);
//                 tileSelected = true;
//                 std::ostringstream oss;
//                 oss << "Tile Position: (" << tile.getX() << ", " << tile.getY() << ")\t\t\t";
//                 const std::unordered_map<int, int>& resources = tile.getResources();
//                 const std::unordered_map<int, int>& characters = tile.getCharacters();
//                 int totalCharacters = 0;
//                 for (const auto& pair : characters) {
//                     totalCharacters += pair.second;
//                 }
//                 oss << "Total Characters: " << totalCharacters << "\n\n";
//                 oss << "Resources:\n";
//                 for (size_t i = 0; i < 7; ++i) {
//                     if (i < resources.size()) {
//                         auto it = std::next(resources.begin(), i);
//                         int resourceId = it->first;
//                         int quantity = it->second;
//                         oss << "Resource " << resourceId << ": " << quantity << "\t\t";
//                     }
//                 }
//                 infoText.setString(oss.str());
//                 return;
//             }
//         }
//     }
//     tileSelected = false;
// }

void print_usage(const std::string& program_name) {
    std::cerr << "USAGE: " << program_name << " -p port -h machine" << std::endl;
    std::cerr << "option description" << std::endl;
    std::cerr << "-p port port number" << std::endl;
    std::cerr << "-h machine hostname of the server" << std::endl;
}

int main(int argc, char *const *argv)
{
    if (argc != 5) {
        print_usage(argv[0]);
        return 1;
    }

    std::string host;
    short port = 0;

    for (int i = 1; i < argc; i += 2) {
        std::string option = argv[i];
        if (option == "-p") {
            port = std::atoi(argv[i + 1]);
        } else if (option == "-h") {
            host = argv[i + 1];
        } else {
            print_usage(argv[0]);
            return 1;
        }
    }

    if (port == 0 || host.empty()) {
        print_usage(argv[0]);
        return 84;
    }

    try {
        Client client(host, port);
        client.start_cli();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
    // sf::RenderWindow window(sf::VideoMode(1920, 1080), "ZAPPY");
    // std::srand(static_cast<unsigned>(std::time(0)));
    // window.setFramerateLimit(30);
    // sf::View view = window.getDefaultView();
    // std::vector<std::vector<Tile>> tiles;

    // sf::Texture parallax1;
    // parallax1.loadFromFile("assets/parallax1.png");
    // sf::Texture parallax2;
    // parallax2.loadFromFile("assets/parallax2.png");
    // sf::Texture parallax3;
    // parallax3.loadFromFile("assets/parallax3.png");
    // sf::Texture parallax4;
    // parallax4.loadFromFile("assets/parallax4.png");

    // sf::Sprite backgroundLayer1(parallax1);
    // sf::Sprite backgroundLayer2(parallax2);
    // sf::Sprite backgroundLayer3(parallax3);
    // sf::Sprite backgroundLayer4(parallax4);

    // backgroundLayer1.setScale(10.0f, 10.0f);
    // backgroundLayer2.setScale(10.0f, 10.0f);
    // backgroundLayer3.setScale(10.0f, 10.0f);
    // backgroundLayer4.setScale(10.0f, 10.0f);
    // backgroundLayer1.setPosition(-1920, -1080);
    // backgroundLayer2.setPosition(-1920, -1080);
    // backgroundLayer3.setPosition(-1920, -1080);
    // backgroundLayer4.setPosition(-1920, -1080);

    // sf::Texture groundTexture;
    // groundTexture.loadFromFile("assets/tile.png");

    // sf::Texture foodTexture;
    // foodTexture.loadFromFile("assets/food.png");
    // sf::Texture linemateTexture;
    // linemateTexture.loadFromFile("assets/linemate.png");
    // sf::Texture deraumereTexture;
    // deraumereTexture.loadFromFile("assets/deraumere.png");
    // sf::Texture siburTexture;
    // siburTexture.loadFromFile("assets/sibur.png");
    // sf::Texture mendianeTexture;
    // mendianeTexture.loadFromFile("assets/mendiane.png");
    // sf::Texture phirasTexture;
    // phirasTexture.loadFromFile("assets/phiras.png");
    // sf::Texture thystameTexture;
    // thystameTexture.loadFromFile("assets/thystame.png");

    // sf::Texture mageTexture;
    // mageTexture.loadFromFile("assets/mage.png");

    // std::unordered_map<int, sf::Texture*> textures = {
    //     {0, &foodTexture},
    //     {1, &linemateTexture},
    //     {2, &deraumereTexture},
    //     {3, &siburTexture},
    //     {4, &mendianeTexture},
    //     {5, &phirasTexture},
    //     {6, &thystameTexture},
    //     {10, &mageTexture},
    //     {11, &mageTexture},
    //     {12, &mageTexture},
    // };

    // sf::Music music;
    // if (!music.openFromFile("assets/music.ogg")) {
    //     return -1;
    // }
    // music.setLoop(true);
    // music.setVolume(10);
    // music.play();

    // const int groundTileWidth = 32;
    // const int groundTileHeight = 32;
    // const int groundTileCount = 6;

    // for (int row = 0; row < boardHeight; ++row) {
    //     std::vector<Tile> rowTiles;
    //     for (int col = 0; col < boardWidth; ++col) {
    //         int tileIndex = std::rand() % groundTileCount;
    //         sf::IntRect textureRect(tileIndex * groundTileWidth, 0, groundTileWidth, groundTileHeight);
    //         Tile tile(col, row, groundTexture, textureRect);
    //         rowTiles.push_back(tile);
    //     }
    //     tiles.push_back(rowTiles);
    // }

    // sf::RectangleShape infoRect(sf::Vector2f(window.getSize().x, 150));
    // infoRect.setFillColor(sf::Color(0, 0, 0, 150));
    // infoRect.setPosition(0, window.getSize().y - 150);
    // sf::Font font;
    // if (!font.loadFromFile("assets/font.ttf")) {
    //     return -1;
    // }
    // sf::Text infoText("", font, 30);
    // infoText.setFillColor(sf::Color::White);
    // infoText.setPosition(10, window.getSize().y - 150);
    // bool tileSelected = false;

    // while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //         else if (event.type == sf::Event::MouseWheelScrolled) {
    //             if (event.mouseWheelScroll.delta > 0) {
    //                 view.zoom(1.0f / zoomCam);
    //             } else if (event.mouseWheelScroll.delta < 0) {
    //                 view.zoom(zoomCam);
    //             }
    //         }
    //         else if (event.type == sf::Event::MouseMoved) {
    //             for (auto& row : tiles) {
    //                 for (auto& tile : row) {
    //                     if (tile.contains(worldPos)) {
    //                         tile.setHovered(true);
    //                     } else {
    //                         tile.setHovered(false);
    //                     }
    //                 }
    //             }
    //         }
    //         else if (event.type == sf::Event::MouseButtonPressed){
    //             handleMouseClick(window, tiles, sf::Vector2i(worldPos), tileSelected, infoText, textures);
    //         }
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
    //         view.move(0, -moveSpeed);
    //         moveParallax(backgroundLayer1, 0.1f, sf::Vector2f(0, -moveSpeed));
    //         moveParallax(backgroundLayer2, 0.2f, sf::Vector2f(0, -moveSpeed));
    //         moveParallax(backgroundLayer3, 0.3f, sf::Vector2f(0, -moveSpeed));
    //         moveParallax(backgroundLayer4, 0.4f, sf::Vector2f(0, -moveSpeed));
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    //         view.move(0, moveSpeed);
    //         moveParallax(backgroundLayer1, 0.1f, sf::Vector2f(0, moveSpeed));
    //         moveParallax(backgroundLayer2, 0.2f, sf::Vector2f(0, moveSpeed));
    //         moveParallax(backgroundLayer3, 0.3f, sf::Vector2f(0, moveSpeed));
    //         moveParallax(backgroundLayer4, 0.4f, sf::Vector2f(0, moveSpeed));
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
    //         view.move(-moveSpeed, 0);
    //         moveParallax(backgroundLayer1, 0.1f, sf::Vector2f(-moveSpeed, 0));
    //         moveParallax(backgroundLayer2, 0.2f, sf::Vector2f(-moveSpeed, 0));
    //         moveParallax(backgroundLayer3, 0.3f, sf::Vector2f(-moveSpeed, 0));
    //         moveParallax(backgroundLayer4, 0.4f, sf::Vector2f(-moveSpeed, 0));
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    //         view.move(moveSpeed, 0);
    //         moveParallax(backgroundLayer1, 0.1f, sf::Vector2f(moveSpeed, 0));
    //         moveParallax(backgroundLayer2, 0.2f, sf::Vector2f(moveSpeed, 0));
    //         moveParallax(backgroundLayer3, 0.3f, sf::Vector2f(moveSpeed, 0));
    //         moveParallax(backgroundLayer4, 0.4f, sf::Vector2f(moveSpeed, 0));
    //     }

    //     /* Press A to randomly change the tiles ressources (will be replaced) */

    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    //         std::unordered_map<int, int> newResources = {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}};
    //         for (int i = 0; i < boardWidth; i++)
    //             for (int j = 0; j < boardHeight; j++)
    //                 tiles[i][j].setResources(newResources, textures);
    //     }

    //     /* Press C to add characters (will be replaced) */

    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
    //         std::unordered_map<int, int> newCharacters = {{10, 1}, {11, 1}, {12, 1}};
    //         tiles[5][5].setCharacters(newCharacters, textures);
    //         tiles[0][3].setCharacters(newCharacters, textures);
    //     }

    //     updateBoard(tiles);
    //     window.clear();
    //     window.setView(view);

    //     window.draw(backgroundLayer1);
    //     window.draw(backgroundLayer2);
    //     window.draw(backgroundLayer3);
    //     window.draw(backgroundLayer4);

    //     drawBoard(window, tiles);
    //     window.setView(window.getDefaultView());
    //     if (tileSelected) {
    //         window.draw(infoRect);
    //         window.draw(infoText);
    //     }
    //     window.display();
    // }
    // return 0;
}
