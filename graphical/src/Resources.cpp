/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Resources
*/

#include "Resources.hpp"
#include <iostream>

/**
 * @brief Constructor for the Resources class.
 * @param x The x position of the resources.
 * @param y The y position of the resources.
 * @param food The food of the resources.
 * @param linemate The linemate of the resources.
 * @param deraumere The deraumere of the resources.
 * @param sibur The sibur of the resources.
 * @param mendiane The mendiane of the resources.
 * @param phiras The phiras of the resources.
 * @param thystame The thystame of the resources.
 */
Resources::Resources(int x, int y, int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
    : x_(x), y_(y), food_(food), linemate_(linemate), deraumere_(deraumere), sibur_(sibur), mendiane_(mendiane), phiras_(phiras), thystame_(thystame) {}

/**
 * @brief Get the x position of the resources.
 * @return The x position of the resources.
 */
int Resources::getX() const {
    return x_;
}

/**
 * @brief Get the y position of the resources.
 * @return The y position of the resources.
 */
int Resources::getY() const {
    return y_;
}

/**
 * @brief Get the food of the resources.
 * @return The food of the resources.
 */
int Resources::getFood() const {
    return food_;
}

/**
 * @brief Get the linemate of the resources.
 * @return The linemate of the resources.
 */
int Resources::getLinemate() const {
    return linemate_;
}

/**
 * @brief Get the deraumere of the resources.
 * @return The deraumere of the resources.
 */
int Resources::getDeraumere() const {
    return deraumere_;
}

/**
 * @brief Get the sibur of the resources.
 * @return The sibur of the resources.
 */
int Resources::getSibur() const {
    return sibur_;
}

/**
 * @brief Get the mendiane of the resources.
 * @return The mendiane of the resources.
 */
int Resources::getMendiane() const {
    return mendiane_;
}

/**
 * @brief Get the phiras of the resources.
 * @return The phiras of the resources.
 */
int Resources::getPhiras() const {
    return phiras_;
}

/**
 * @brief Get the thystame of the resources.
 * @return The thystame of the resources.
 */
int Resources::getThystame() const {
    return thystame_;
}

/**
 * @brief Set the x position of the resources.
 * @param x The x position of the resources.
 */
void Resources::setX(int x) {
    x_ = x;
}

/**
 * @brief Set the y position of the resources.
 * @param y The y position of the resources.
 */
void Resources::setY(int y) {
    y_ = y;
}

/**
 * @brief Set the food of the resources.
 * @param food The food of the resources.
 */
void Resources::setFood(int food) {
    food_ = food;
}

/**
 * @brief Set the linemate of the resources.
 * @param linemate The linemate of the resources.
 */
void Resources::setLinemate(int linemate) {
    linemate_ = linemate;
}

/**
 * @brief Set the deraumere of the resources.
 * @param deraumere The deraumere of the resources.
 */
void Resources::setDeraumere(int deraumere) {
    deraumere_ = deraumere;
}

/**
 * @brief Set the sibur of the resources.
 * @param sibur The sibur of the resources.
 */
void Resources::setSibur(int sibur) {
    sibur_ = sibur;
}

/**
 * @brief Set the mendiane of the resources.
 * @param mendiane The mendiane of the resources.
 */
void Resources::setMendiane(int mendiane) {
    mendiane_ = mendiane;
}

/**
 * @brief Set the phiras of the resources.
 * @param phiras The phiras of the resources.
 */
void Resources::setPhiras(int phiras) {
    phiras_ = phiras;
}

/**
 * @brief Set the thystame of the resources.
 * @param thystame The thystame of the resources.
 */
void Resources::setThystame(int thystame) {
    thystame_ = thystame;
}

/**
 * @brief Set the textures of the resources.
 * @param textures The textures of the resources.
 */
void Resources::setTextures(const std::unordered_map<int, sf::Texture*>& textures) {
    sprites.clear();
    resourceFrames.clear();

    for (int i = 0; i < 7; i++) {
        sf::Sprite sprite;
        sprite.setTexture(*textures.at(i));
        sprite.setScale(36.0f / 16.0f, 36.0f / 16.0f);
        float offsetX = static_cast<float>(std::rand() % static_cast<int>(100.0f - 36.0f));
        float offsetY = static_cast<float>(std::rand() % static_cast<int>(100.0f / 1.5f - 36.0f));
        sprite.setPosition(x_ * 100.0f + offsetX, y_ * 100.0f + offsetY);
        sprite.setTextureRect(sf::IntRect(0, 0, 16.0f, 16.0f));
        sprites.push_back(sprite);
        resourceFrames.push_back(0);
    }
}

/**
 * @brief Update the animation of the resources.
 */
void Resources::updateAnimation()
{
    if (animationClock.getElapsedTime().asSeconds() > 0.2f) {
        for (size_t i = 0; i < resourceFrames.size(); ++i) {
            resourceFrames[i] = (resourceFrames[i] + 1) % 4;
            sprites[i].setTextureRect(sf::IntRect(resourceFrames[i] * 16.0f, 0, 16.0f, 16.0f));
        }
        animationClock.restart();
    }
}

/**
 * @brief Draw the resources.
 * @param window The window to draw the resources on.
 */
void Resources::draw(sf::RenderWindow &window) const {
    if (getFood() > 0) {
        window.draw(sprites[0]);
    }
    if (getLinemate() > 0) {
        window.draw(sprites[1]);
    }
    if (getDeraumere() > 0) {
        window.draw(sprites[2]);
    }
    if (getSibur() > 0) {
        window.draw(sprites[3]);
    }
    if (getMendiane() > 0) {
        window.draw(sprites[4]);
    }
    if (getPhiras() > 0) {
        window.draw(sprites[5]);
    }
    if (getThystame() > 0) {
        window.draw(sprites[6]);
    }
}
