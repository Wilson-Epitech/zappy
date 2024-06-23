/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Character
*/

#include "Character.hpp"
#include <iostream>

Character::Character(int id, int pos_x, int pos_y, int orientation, int level, const std::string& team)
    : id_(id), pos_x_(pos_x), pos_y_(pos_y), orientation_(orientation), level_(level), team_(team) {}

int Character::getId() const {
    return id_;
}

int Character::getPosX() const {
    return pos_x_;
}

int Character::getPosY() const {
    return pos_y_;
}

int Character::getOrientation() const {
    return orientation_;
}

int Character::getLevel() const {
    return level_;
}

std::string Character::getTeam() const {
    return team_;
}

bool Character::getIsDead() const {
    return isDead_;
}

void Character::setId(int id) {
    id_ = id;
}

void Character::setPosX(int pos_x) {
    pos_x_ = pos_x;
}

void Character::setPosY(int pos_y) {
    pos_y_ = pos_y;
}

void Character::setOrientation(int orientation) {
    orientation_ = orientation;
}

void Character::setLevel(int level) {
    level_ = level;
}

void Character::setTeam(const std::string& team) {
    team_ = team;
}

void Character::setIsDead(bool isDead) {
    isDead_ = isDead;
}

bool Character::contains(const sf::Vector2f& point) const {
    return sprite.getGlobalBounds().contains(point);
}

void Character::setTextures(const std::unordered_map<int, sf::Texture*>& textures, Client& client) {
    static std::vector<sf::Color> colors = {
        sf::Color::Blue, sf::Color::Red, sf::Color::Green, sf::Color::Yellow,
        sf::Color::Magenta, sf::Color::Cyan
    };
    int colorIndex = 0;
    if (!textureLoaded_) {
        sprite.setScale(100.0f / 36.0f, 100.0f / 24.0f);
        characterFrames.push_back(0);
        textureLoaded_ = true;
    }
    switch (orientation_) {
        case 1: sprite.setTexture(*textures.at(10)); break;
        case 2: sprite.setTexture(*textures.at(11)); break;
        case 3: sprite.setTexture(*textures.at(12)); break;
        case 4: sprite.setTexture(*textures.at(13)); break;
    }
    for (auto &team : client.getTeamNames()) {
        ++colorIndex;
        if (team_.compare(team) == 0) {
            sprite.setColor(colors[colorIndex]);
        }
    }
    sprite.setPosition(pos_x_ * 100.0f + 25.0f, pos_y_ * 100.0f - 25.0f);
}

void Character::updateAnimation() {
    if (animationClock.getElapsedTime().asSeconds() > 0.2f) {
        for (size_t i = 0; i < characterFrames.size(); ++i) {
            characterFrames[i] = (characterFrames[i] + 1) % 3;
            sprite.setTextureRect(sf::IntRect(characterFrames[i] * 16, 0, 16, 32));
        }
        animationClock.restart();
    }
}

void Character::draw(sf::RenderWindow &window) const{
    if (!this->isDead_) {
        window.draw(sprite);
    }
}
