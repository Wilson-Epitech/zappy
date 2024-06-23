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
     * @brief 
     * 
     * @return int 
     */
    int getX() const;
    /**
     * @brief 
     * 
     * @return int 
     */
    int getY() const;
    /**
     * @brief 
     * 
     * @return int 
     */
    int getFood() const;
    /**
     * @brief 
     * 
     * @return int 
     */
    int getLinemate() const;
    /**
     * @brief 
     * 
     * @return int 
     */
    int getDeraumere() const;
    /**
     * @brief 
     * 
     * @return int 
     */
    int getSibur() const;
    /**
     * @brief 
     * 
     * @return int 
     */
    int getMendiane() const;
    /**
     * @brief 
     * 
     * @return int 
     */
    int getPhiras() const;
    /**
     * @brief 
     * 
     * @return int 
     */
    int getThystame() const;

    /**
     * @brief 
     * 
     * @param x 
     */
    void setX(int x);
    /**
     * @brief 
     * 
     * @param y 
     */
    void setY(int y);
    /**
     * @brief 
     * 
     * @param food 
     */
    void setFood(int food);
    /**
     * @brief 
     * 
     * @param linemate 
     */
    void setLinemate(int linemate);
    /**
     * @brief 
     * 
     * @param deraumere 
     */
    void setDeraumere(int deraumere);
    /**
     * @brief 
     * 
     * @param sibur 
     */
    void setSibur(int sibur);
    /**
     * @brief 
     * 
     * @param mendiane 
     */
    void setMendiane(int mendiane);
    /**
     * @brief 
     * 
     * @param phiras 
     */
    void setPhiras(int phiras);
    /**
     * @brief 
     * 
     * @param thystame 
     */
    void setThystame(int thystame);

    /**
     * @brief 
     * 
     * @param textures 
     */
    void setTextures(const std::unordered_map<int, sf::Texture*>& textures);
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
