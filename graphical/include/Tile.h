#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "Resources.hpp"

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
    void setSelected(bool selected);
    bool isSelected() const;

    const std::unordered_map<int, int>& getResources() const {
        return resources.getResources();
    }

    const std::unordered_map<int, int>& getCharacters() const {
        return characters;
    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }

private:
    int x;
    int y;
    bool isHovered;
    bool selected;
    sf::Color originalColor;
    sf::Sprite sprite;

    Resources resources;
    std::unordered_map<int, int> characters;
    std::vector<sf::Sprite> characterSprites;

    static const float animationSpeed;
    sf::Clock animationClock;
    sf::Clock characterClock;
    std::vector<int> characterFrames;

    void updateCharacterSprites(const std::unordered_map<int, sf::Texture*>& textures);
    void setOriginalColor();
};

#endif /* TILE_H_ */
