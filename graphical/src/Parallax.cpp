/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Parallax
*/

#include "../include/Parallax.hpp"

Parallax::Parallax() {
    parallaxTextures[0].loadFromFile("assets/parallax1.png");
    parallaxTextures[1].loadFromFile("assets/parallax2.png");
    parallaxTextures[2].loadFromFile("assets/parallax3.png");
    parallaxTextures[3].loadFromFile("assets/parallax4.png");

    for (int i = 0; i < 4; ++i) {
        parallaxSprites[i].setTexture(parallaxTextures[i]);
        parallaxSprites[i].setScale(10.0f, 10.0f);
        parallaxSprites[i].setPosition(-1920, -1080);
    }
}

void Parallax::move(sf::Sprite& layer, sf::Vector2f direction) {
    layer.move(direction);
    if (layer.getPosition().x < -layer.getGlobalBounds().width) {
        layer.setPosition(layer.getPosition().x + layer.getGlobalBounds().width * 2, layer.getPosition().y);
    }
    if (layer.getPosition().x > layer.getGlobalBounds().width) {
        layer.setPosition(layer.getPosition().x - layer.getGlobalBounds().width * 2, layer.getPosition().y);
    }
}

void Parallax::update(float offsetX, float offsetY) {
    for (int i = 0; i < 4; ++i) {
        move(parallaxSprites[i], sf::Vector2f(offsetX * (i + 1), offsetY * (i + 1)));
    }
}

void Parallax::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; ++i) {
        window.draw(parallaxSprites[i]);
    }
}

