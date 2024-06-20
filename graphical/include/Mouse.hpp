#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "Tile.h"
#include "Menu.hpp"
#include "Camera.hpp"

class Mouse {
public:
    Mouse();

    void handleMouseScroll(sf::View& view, const sf::Event& event, Camera& camera);
    void handleMouseMove(const sf::Vector2f& worldPos, std::vector<std::vector<Tile>>& tiles);
    void handleMouseClick(sf::RenderWindow& window, const sf::Vector2f& worldPos, std::vector<std::vector<Tile>>& tiles, Tile*& selectedTile, Menu& menu, bool& tileSelected);
    void handleAllMouseEvents(sf::RenderWindow& window, sf::View& view, const sf::Event& event, std::vector<std::vector<Tile>>& tiles, Tile*& selectedTile, Menu& menu, bool& tileSelected, Camera& camera);
};

#endif // MOUSE_HPP
