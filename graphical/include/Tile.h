/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Tile
*/

#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Tile {
public:
    Tile(int x, int y, sf::Texture& texture, const sf::IntRect& textureRect);
    ~Tile();

    void drawTile(sf::RenderWindow &window) const;
    void setResources(const std::unordered_map<int, int>& resources, const std::unordered_map<int, sf::Texture*>& textures);
    void updateAnimation();

private:
    int x;
    int y;
    sf::Sprite sprite;
    std::unordered_map<int, int> resources;
    std::vector<sf::Sprite> resourceSprites;
    static const float animationSpeed;
    sf::Clock animationClock;
    const float frameWidth = 16;
    const float frameHeight = 16;
    const int frameCount = 4;
    std::vector<int> currentFrames;

    void updateResourceSprites(const std::unordered_map<int, sf::Texture*>& textures);
};

#endif /* TILE_H_ */
