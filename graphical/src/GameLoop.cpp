/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** GameLoop
*/

#include "GameLoop.hpp"
#include "Character.hpp"
#include "Resources.hpp"
#include "Tile.hpp"

void drawBoard(sf::RenderWindow& window, const std::vector<std::vector<Tile>>& tiles) {
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            tile.drawTile(window);
        }
    }
}

void drawResources(sf::RenderWindow& window, const std::vector<Resources>& resources) {
    for (const auto& resource : resources) {
        resource.draw(window);
    }
}

void updateResources(std::vector<Resources>& resources) {
    for (auto& resource : resources) {
        resource.updateAnimation();
    }
}

void drawCharacters(sf::RenderWindow& window, const std::vector<Character>& characters) {
    for (const auto& character : characters) {
        character.draw(window);
    }
}

void updateCharacters(std::vector<Character>& characters) {
    for (auto& character : characters) {
        character.updateAnimation();
    }
}

void gameLoop(Client& client) {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ZAPPY");
    std::srand(static_cast<unsigned>(std::time(0)));
    window.setFramerateLimit(30);
    sf::View view = window.getDefaultView();
    std::vector<std::vector<Tile>> tiles;
    sf::Clock updateClock;

    Music music;
    Camera camera;
    Parallax parallax;
    Menu menu(window.getSize());
    Mouse mouse;

    sf::Texture groundTexture;
    if (!groundTexture.loadFromFile("graphical/assets/tile.png"))
        return;

    sf::Texture foodTexture;
    if (!foodTexture.loadFromFile("graphical/assets/food.png"))
        return;

    sf::Texture linemateTexture;
    if (!linemateTexture.loadFromFile("graphical/assets/linemate.png"))
        return;
    sf::Texture deraumereTexture;
    if (!deraumereTexture.loadFromFile("graphical/assets/deraumere.png"))
        return;
    sf::Texture siburTexture;
    if (!siburTexture.loadFromFile("graphical/assets/sibur.png"))
        return;
    sf::Texture mendianeTexture;
    if (!mendianeTexture.loadFromFile("graphical/assets/mendiane.png"))
        return;
    sf::Texture phirasTexture;
    if (!phirasTexture.loadFromFile("graphical/assets/phiras.png"))
        return;
    sf::Texture thystameTexture;
    if (!thystameTexture.loadFromFile("graphical/assets/thystame.png"))
        return;

    sf::Texture upMage;
    if (!upMage.loadFromFile("graphical/assets/upMage.png"))
        return;
    sf::Texture rightMage;
    if (!rightMage.loadFromFile("graphical/assets/rightMage.png"))
        return;
    sf::Texture downMage;
    if (!downMage.loadFromFile("graphical/assets/downMage.png"))
        return;
    sf::Texture leftMage;
    if (!leftMage.loadFromFile("graphical/assets/leftMage.png"))
        return;

    std::unordered_map<int, sf::Texture*> textures = {
        {0, &foodTexture},
        {1, &linemateTexture},
        {2, &deraumereTexture},
        {3, &siburTexture},
        {4, &mendianeTexture},
        {5, &phirasTexture},
        {6, &thystameTexture},
        {10, &upMage},
        {11, &rightMage},
        {12, &downMage},
        {13, &leftMage},
    };

    music.play();
    int width = client.getMapWidth();
    int height = client.getMapHeight();

    for (int row = 0; row < width; ++row) {
        std::vector<Tile> rowTiles;
        for (int col = 0; col < height; ++col) {
            int tileIndex = std::rand() % 6;
            sf::IntRect textureRect(tileIndex * 32, 0, 32, 32);
            Tile tile(col, row, groundTexture, textureRect);
            rowTiles.push_back(tile);
        }
        tiles.push_back(rowTiles);
    }

    Tile* selectedTile = nullptr;
    bool tileSelected = false;
    const Character* selectedCharacter = nullptr;
    bool characterSelected = false;

    std::vector<Character> characters;
    std::vector<Resources> resources;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            mouse.handleAllMouseEvents(window, view, event, tiles, selectedTile, selectedCharacter,
            menu, tileSelected, characterSelected, camera, resources, characters, client);
        }
        camera.handleMovement(view, parallax);
        if (updateClock.getElapsedTime().asSeconds() >= 1.0) {
            characters = client.getCharacters();
            resources = client.getResources();
            for (auto& character : characters) {
                character.setTextures(textures, client);
            }
            for (auto& resource : resources) {
                resource.setTextures(textures);
            }
            updateClock.restart();
        }

        updateResources(resources);
        updateCharacters(characters);
        window.clear();
        window.setView(view);
        parallax.draw(window);
        drawBoard(window, tiles);
        drawResources(window, resources);
        drawCharacters(window, characters);
        window.setView(window.getDefaultView());
        menu.draw(window, tileSelected, characterSelected);
        window.display();
    }
}
