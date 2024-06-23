/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Resources
*/

#include "Resources.hpp"
#include <iostream>

Resources::Resources(int x, int y, int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
    : x_(x), y_(y), food_(food), linemate_(linemate), deraumere_(deraumere), sibur_(sibur), mendiane_(mendiane), phiras_(phiras), thystame_(thystame) {}

int Resources::getX() const {
    return x_;
}

int Resources::getY() const {
    return y_;
}

int Resources::getFood() const {
    return food_;
}

int Resources::getLinemate() const {
    return linemate_;
}

int Resources::getDeraumere() const {
    return deraumere_;
}

int Resources::getSibur() const {
    return sibur_;
}

int Resources::getMendiane() const {
    return mendiane_;
}

int Resources::getPhiras() const {
    return phiras_;
}

int Resources::getThystame() const {
    return thystame_;
}

void Resources::setX(int x) {
    x_ = x;
}

void Resources::setY(int y) {
    y_ = y;
}

void Resources::setFood(int food) {
    food_ = food;
}

void Resources::setLinemate(int linemate) {
    linemate_ = linemate;
}

void Resources::setDeraumere(int deraumere) {
    deraumere_ = deraumere;
}

void Resources::setSibur(int sibur) {
    sibur_ = sibur;
}

void Resources::setMendiane(int mendiane) {
    mendiane_ = mendiane;
}

void Resources::setPhiras(int phiras) {
    phiras_ = phiras;
}

void Resources::setThystame(int thystame) {
    thystame_ = thystame;
}

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
