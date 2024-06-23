/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Character
*/

#include "Character.hpp"
#include <iostream>

/**
 * @brief Constructor for the Character class.
 * @param id The id of the character.
 * @param pos_x The x position of the character.
 * @param pos_y The y position of the character.
 * @param orientation The orientation of the character.
 * @param level The level of the character.
 * @param team The team of the character.
*/
Character::Character(int id, int pos_x, int pos_y, int orientation, int level, const std::string& team)
    : id_(id), pos_x_(pos_x), pos_y_(pos_y), orientation_(orientation), level_(level), team_(team) {}

/**
 * @brief Get the id of the character.
 * @return The id of the character.
*/
int Character::getId() const {
    return id_;
}

/**
 * @brief Get the x position of the character.
 * @return The x position of the character. 
*/
int Character::getPosX() const {
    return pos_x_;
}

/**
 * @brief Get the y position of the character.
 * @return The y position of the character.
*/
int Character::getPosY() const {
    return pos_y_;
}

/**
 * @brief Get the orientation of the character.
 * @return The orientation of the character.
*/
int Character::getOrientation() const {
    return orientation_;
}

/**
 * @brief Get the level of the character.
 * @return The level of the character.
*/
int Character::getLevel() const {
    return level_;
}

/**
 * @brief Get the team of the character.
 * @return The team of the character.
*/
std::string Character::getTeam() const {
    return team_;
}

/**
 * @brief Get the isDead status of the character.
 * @return The isDead status of the character.
*/
bool Character::getIsDead() const {
    return isDead_;
}

/**
 * @brief Set the id of the character.
 * @param id The id of the character.
*/
void Character::setId(int id) {
    id_ = id;
}

/**
 * @brief Set the x position of the character.
 * @param pos_x The x position of the character.
*/
void Character::setPosX(int pos_x) {
    pos_x_ = pos_x;
}

/**
 * @brief Set the y position of the character.
 * @param pos_y The y position of the character.
*/
void Character::setPosY(int pos_y) {
    pos_y_ = pos_y;
}

/**
 * @brief Set the orientation of the character.
 * @param orientation The orientation of the character.
*/
void Character::setOrientation(int orientation) {
    orientation_ = orientation;
}

/**
 * @brief Set the level of the character.
 * @param level The level of the character.
*/
void Character::setLevel(int level) {
    level_ = level;
}

/**
 * @brief Set the team of the character.
 * @param team The team of the character.
*/
void Character::setTeam(const std::string& team) {
    team_ = team;
}

/**
 * @brief Set the isDead status of the character.
 * @param isDead The isDead status of the character.
*/
void Character::setIsDead(bool isDead) {
    isDead_ = isDead;
}

/**
 * @brief Check if the character contains a point.
 * @param point The point to check.
 * @return True if the character contains the point, false otherwise.
*/
bool Character::contains(const sf::Vector2f& point) const {
    return sprite.getGlobalBounds().contains(point);
}

/**
 * @brief Set the textures of the character.
 * @param textures The textures to set.
 * @param client The client instance.
*/
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

/**
 * @brief Update the animation of the character.
*/
void Character::updateAnimation() {
    if (animationClock.getElapsedTime().asSeconds() > 0.2f) {
        for (size_t i = 0; i < characterFrames.size(); ++i) {
            characterFrames[i] = (characterFrames[i] + 1) % 3;
            sprite.setTextureRect(sf::IntRect(characterFrames[i] * 16, 0, 16, 32));
        }
        animationClock.restart();
    }
}

/**
 * @brief Draw the character.
 * @param window The window to draw the character on.
*/
void Character::draw(sf::RenderWindow &window) const{
    if (!this->isDead_) {
        window.draw(sprite);
    }
}
