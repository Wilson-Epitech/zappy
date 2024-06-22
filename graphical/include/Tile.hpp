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
#include "Resources.hpp"

class Tile {
public:
    Tile(int x, int y, sf::Texture& texture, const sf::IntRect& textureRect);
    ~Tile();

    void drawTile(sf::RenderWindow &window) const;

    void setHovered(bool hovered);
    bool contains(const sf::Vector2f& point) const;
    void setSelected(bool selected);
    bool isSelected() const;

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

    void setOriginalColor();
};

#endif /* TILE_H_ */
