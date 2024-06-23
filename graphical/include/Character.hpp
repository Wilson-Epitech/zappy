/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Character
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Client.hpp"

class Client;

/**
 * @brief
 *
 */
class Character {
public:
    /**
     * @brief Construct a new Character object
     *
     * @param id
     * @param pos_x
     * @param pos_y
     * @param orientation
     * @param level
     * @param team
     */
    Character(int id, int pos_x, int pos_y, int orientation, int level, const std::string& team);
    /**
     * @brief Get the Id object
     *
     * @return int
     */
    int getId() const;
    /**
     * @brief Get the Pos X object
     *
     * @return int
     */
    int getPosX() const;
    /**
     * @brief Get the Pos Y object
     *
     * @return int
     */
    int getPosY() const;
    /**
     * @brief Get the Orientation object
     *
     * @return int
     */
    int getOrientation() const;
    /**
     * @brief Get the Level object
     *
     * @return int
     */
    int getLevel() const;
    /**
     * @brief Get the Team object
     *
     * @return std::string
     */
    std::string getTeam() const;
    /**
     * @brief Get the Is Dead object
     *
     * @return true
     * @return false
     */
    bool getIsDead() const;
    /**
     * @brief Set the Id object
     *
     * @param id
     */
    void setId(int id);
    /**
     * @brief Set the Pos X object
     *
     * @param pos_x
     */
    void setPosX(int pos_x);
    /**
     * @brief Set the Pos Y object
     *
     * @param pos_y
     */
    void setPosY(int pos_y);
    /**
     * @brief Set the Orientation object
     *
     * @param orientation
     */
    void setOrientation(int orientation);
    /**
     * @brief Set the Level object
     *
     * @param level
    */
    void setLevel(int level);
    /**
     * @brief Set the Team object
     *
     * @param team
     */
    void setTeam(const std::string& team);
    /**
     * @brief Set the Is Dead object
     *
     * @param isDead
     */
    void setIsDead(bool isDead);
    /**
     * @brief
     *
     * @param point
     * @return true
     * @return false
     */
    bool contains(const sf::Vector2f& point) const;

    /**
     * @brief Set the Textures object
     *
     * @param textures
     * @param client
     */
    void setTextures(const std::unordered_map<int, sf::Texture*>& textures, Client& client);
    /**
     * @brief
     *
     */
    void updateAnimation();
    /**
     * @brief
     *
     * @param window
     */
    void draw(sf::RenderWindow &window) const;

private:
    int id_;
    int pos_x_;
    int pos_y_;
    int orientation_;
    int level_;
    bool isDead_ = false;
    std::string team_;

    bool textureLoaded_ = false;
    int spriteHeight_;
    sf::Sprite sprite;
    std::vector<int> characterFrames;
    sf::Clock animationClock;
};

#endif // CHARACTER_HPP
