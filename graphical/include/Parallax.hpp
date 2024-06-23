/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Parallax
*/

#ifndef PARALLAX_HPP_
#define PARALLAX_HPP_

#include <SFML/Graphics.hpp>

/**
 * @brief Class representing the Parallax
 *
 */
class Parallax {
public:
    /**
     * @brief Construct a new Parallax object
     *
     */
    Parallax();

    /**
     * @brief Move the parallax
     *
     * @param layer
     * @param direction
     */
    void move(sf::Sprite& layer, sf::Vector2f direction);
    /**
     * @brief Update the parallax
     *
     * @param offsetX
     * @param offsetY
     */
    void update(float offsetX, float offsetY);
    /**
     * @brief Draw the parallax
     *
     * @param window
     */
    void draw(sf::RenderWindow& window);

private:
    sf::Texture parallaxTextures[4];
    sf::Sprite parallaxSprites[4];
};
#endif /* !PARALLAX_HPP_ */
