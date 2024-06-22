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

class Resources {
public:
    Resources(int x, int y, int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);

    int getX() const;
    int getY() const;
    int getFood() const;
    int getLinemate() const;
    int getDeraumere() const;
    int getSibur() const;
    int getMendiane() const;
    int getPhiras() const;
    int getThystame() const;

    void setX(int x);
    void setY(int y);
    void setFood(int food);
    void setLinemate(int linemate);
    void setDeraumere(int deraumere);
    void setSibur(int sibur);
    void setMendiane(int mendiane);
    void setPhiras(int phiras);
    void setThystame(int thystame);

    void setTextures(const std::unordered_map<int, sf::Texture*>& textures);
    void updateAnimation();
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
