/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Resources
*/

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Resources {
public:
    Resources();
    ~Resources();

    void setResources(const std::unordered_map<int, int>& resources, int x, int y, const std::unordered_map<int, sf::Texture*>& textures);
    void drawResources(sf::RenderWindow &window) const;
    void updateAnimation();
    const std::unordered_map<int, int>& getResources() const;

private:
    std::unordered_map<int, int> resources;
    std::vector<sf::Sprite> resourceSprites;
    std::vector<int> currentFrames;

    static const float animationSpeed;
    sf::Clock animationClock;
    const float squareSize = 100.0f;
    const float resourceSize = 20.0f;
    const float frameWidth = 16;
    const float frameHeight = 16;
    const int frameCount = 4;

    void updateResourceSprites(int x, int y, const std::unordered_map<int, sf::Texture*>& textures);
};

#endif /* RESOURCES_H_ */
