/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Parallax
*/

#ifndef PARALLAX_HPP_
#define PARALLAX_HPP_

#include <SFML/Graphics.hpp>

class Parallax {
public:
    Parallax();

    void move(sf::Sprite& layer, sf::Vector2f direction);
    void update(float offsetX, float offsetY);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture parallaxTextures[4];
    sf::Sprite parallaxSprites[4];
};
#endif /* !PARALLAX_HPP_ */
