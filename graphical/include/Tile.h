/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Tile
*/

#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>
#include <vector>

class Tile {
public:
    Tile(int x, int y, sf::Texture& texture, const sf::IntRect& textureRect);
    ~Tile();

    void drawTile(sf::RenderWindow &window) const;
    void setResources(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);
    void addResourceSprite(sf::Texture& resourceTexture, int count);
    void updateAnimation();

private:
    sf::Sprite sprite;
    int x, y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    std::vector<sf::Sprite> resourceSprites;

    std::vector<int> currentFrames;
    static const int frameCount = 4;
    static const int frameWidth = 16;
    static const int frameHeight = 16;
    static const float animationSpeed;
    sf::Clock animationClock;
};

#endif /* TILE_H_ */
