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
    void setCharacters(const std::unordered_map<int, int>& characters, const std::unordered_map<int, sf::Texture*>& textures);
    void updateAnimation();
    void updateCharacterAnimation();

    void setHovered(bool hovered);
    bool contains(const sf::Vector2f& point) const;

private:
    int x;
    int y;
    bool isHovered;
    sf::Color originalColor;
    sf::Sprite sprite;

    std::unordered_map<int, int> resources;
    std::vector<sf::Sprite> resourceSprites;

    std::unordered_map<int, int> characters;
    std::vector<sf::Sprite> characterSprites;

    static const float animationSpeed;
    sf::Clock animationClock;
    sf::Clock characterClock;
    const float frameWidth = 16;
    const float frameHeight = 16;
    const int frameCount = 4;
    std::vector<int> currentFrames;
    std::vector<int> characterFrames;

    void updateResourceSprites(const std::unordered_map<int, sf::Texture*>& textures);
    void updateCharacterSprites(const std::unordered_map<int, sf::Texture*>& textures);
    void setOriginalColor();
};

#endif /* TILE_H_ */
