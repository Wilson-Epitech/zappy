/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Resources
*/

#ifndef RESOURCES_HPP_
#define RESOURCES_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>

/**
 * @brief Class representing the Resources
 *
 */
class Resources {
public:
    /**
     * @brief Construct a new Resources object
     *
     * @param x
     * @param y
     * @param food
     * @param linemate
     * @param deraumere
     * @param sibur
     * @param mendiane
     * @param phiras
     * @param thystame
     */
    Resources(int x, int y, int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);

    /**
     * @brief Get the X object
     *
     * @return int
     */
    int getX() const;
    /**
     * @brief Get the Y object
     *
     * @return int
     */
    int getY() const;
    /**
     * @brief Get the Food object
     *
     * @return int
     */
    int getFood() const;
    /**
     * @brief Get the Linemate object
     *
     * @return int
     */
    int getLinemate() const;
    /**
     * @brief Get the Deraumere object
     *
     * @return int
     */
    int getDeraumere() const;
    /**
     * @brief Get the Sibur object
     *
     * @return int
     */
    int getSibur() const;
    /**
     * @brief Get the Mendiane object
     *
     * @return int
     */
    int getMendiane() const;
    /**
     * @brief Get the Phiras object
     *
     * @return int
     */
    int getPhiras() const;
    /**
     * @brief Get the Thystame object
     *
     * @return int
     */
    int getThystame() const;

    /**
     * @brief Set the X object
     *
     * @param x
     */
    void setX(int x);
    /**
     * @brief Set the Y object
     *
     * @param y
     */
    void setY(int y);
    /**
     * @brief Set the Food object
     *
     * @param food
     */
    void setFood(int food);
    /**
     * @brief Set the Linemate object
     *
     * @param linemate
     */
    void setLinemate(int linemate);
    /**
     * @brief Set the Deraumere object
     *
     * @param deraumere
     */
    void setDeraumere(int deraumere);
    /**
     * @brief Set the Sibur object
     *
     * @param sibur
     */
    void setSibur(int sibur);
    /**
     * @brief Set the Mendiane object
     *
     * @param mendiane
     */
    void setMendiane(int mendiane);
    /**
     * @brief Set the Phiras object
     *
     * @param phiras
     */
    void setPhiras(int phiras);
    /**
     * @brief Set the Thystame object
     *
     * @param thystame
     */
    void setThystame(int thystame);

    /**
     * @brief Get the Textures object
     *
     * @param textures
     */
    void setTextures(const std::unordered_map<int, sf::Texture*>& textures);
    /**
     * @brief Update the Animation object
     *
     */
    void updateAnimation();
    /**
     * @brief Draw the Resources
     *
     * @param window
     */
    void draw(sf::RenderWindow &window) const;

private:
    int x_;
    int y_;
    int food_;
    int linemate_;
    int deraumere_;
    int sibur_;
    int mendiane_;
    int phiras_;
    int thystame_;

    int spriteHeight_;
    std::vector<sf::Sprite> sprites;
    std::vector<int> resourceFrames;
    sf::Clock animationClock;
};

#endif /* !RESOURCES_HPP */
