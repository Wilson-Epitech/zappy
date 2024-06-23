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

/**
 * @brief Class representing the Tile
 * 
 */
class Tile {
public:
    /**
     * @brief Construct a new Tile object
     * 
     * @param x 
     * @param y 
     * @param texture 
     * @param textureRect 
     */
    Tile(int x, int y, sf::Texture& texture, const sf::IntRect& textureRect);
    ~Tile();

    /**
     * @brief 
     * 
     * @param window 
     */
    void drawTile(sf::RenderWindow &window) const;

    /**
     * @brief Set the Hovered object
     * 
     * @param hovered 
     */
    void setHovered(bool hovered);
    /**
     * @brief 
     * 
     * @return bool 
     */
    bool contains(const sf::Vector2f& point) const;
    /**
     * @brief 
     * 
     * @return bool 
     */
    void setSelected(bool selected);
    /**
     * @brief 
     * 
     * @return bool 
     */
    bool isSelected() const;

    /**
     * @brief 
     * 
     * @param resources 
     */
    int getX() const {
        return x;
    }
    /**
     * @brief 
     * 
     * @return int 
     */
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
