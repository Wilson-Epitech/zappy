/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Parallax
*/

#include "Parallax.hpp"

/**
 * @brief Constructor for the Parallax class.
 */
Parallax::Parallax() {
    if (!parallaxTextures[0].loadFromFile("graphical/assets/parallax1.png"))
        return;
    if (!parallaxTextures[1].loadFromFile("graphical/assets/parallax2.png"))
        return;
    if (!parallaxTextures[2].loadFromFile("graphical/assets/parallax3.png"))
        return;
    if (!parallaxTextures[3].loadFromFile("graphical/assets/parallax4.png"))
        return;

    for (int i = 0; i < 4; ++i) {
        parallaxSprites[i].setTexture(parallaxTextures[i]);
        parallaxSprites[i].setScale(10.0f, 10.0f);
        parallaxSprites[i].setPosition(-1920, -1080);
    }
}

/**
 * @brief Moves the layer.
 * @param layer The layer to move.
 * @param direction The direction to move the layer.
 */
void Parallax::move(sf::Sprite& layer, sf::Vector2f direction) {
    layer.move(direction);
    if (layer.getPosition().x < -layer.getGlobalBounds().width) {
        layer.setPosition(layer.getPosition().x + layer.getGlobalBounds().width * 2, layer.getPosition().y);
    }
    if (layer.getPosition().x > layer.getGlobalBounds().width) {
        layer.setPosition(layer.getPosition().x - layer.getGlobalBounds().width * 2, layer.getPosition().y);
    }
}

/**
 * @brief Updates the parallax.
 * @param offsetX The x offset.
 * @param offsetY The y offset.
 */
void Parallax::update(float offsetX, float offsetY) {
    for (int i = 0; i < 4; ++i) {
        move(parallaxSprites[i], sf::Vector2f(offsetX * (i + 1), offsetY * (i + 1)));
    }
}

/**
 * @brief Draws the parallax.
 * @param window The window to draw the parallax on.
 */
void Parallax::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; ++i) {
        window.draw(parallaxSprites[i]);
    }
}

