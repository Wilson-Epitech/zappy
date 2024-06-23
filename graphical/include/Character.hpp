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

class Character {
public:
    Character(int id, int pos_x, int pos_y, int orientation, int level, const std::string& team);

    int getId() const;
    int getPosX() const;
    int getPosY() const;
    int getOrientation() const;
    int getLevel() const;
    std::string getTeam() const;
    bool getIsDead() const;

    void setId(int id);
    void setPosX(int pos_x);
    void setPosY(int pos_y);
    void setOrientation(int orientation);
    void setLevel(int level);
    void setTeam(const std::string& team);
    void setIsDead(bool isDead);

    void setTextures(const std::unordered_map<int, sf::Texture*>& textures);
    void updateAnimation();
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
