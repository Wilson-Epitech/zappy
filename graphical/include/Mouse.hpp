/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Mouse
*/

#ifndef MOUSE_HPP_
#define MOUSE_HPP_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "Tile.hpp"
#include "Menu.hpp"
#include "Camera.hpp"
#include "Character.hpp"
#include "Client.hpp"

/**
 * @brief Class representing the Mouse
 *
 */
class Mouse {
public:
    /**
     * @brief Construct a new Mouse object
     *
     */
    Mouse();

    /**
     * @brief Handle the mouse scroll
     *
     * @param view
     * @param event
     * @param camera
     */
    void handleMouseScroll(sf::View& view, const sf::Event& event, Camera& camera);
    /**
     * @brief Handle the mouse move
     *
     * @param worldPos
     * @param tiles
     */
    void handleMouseMove(const sf::Vector2f& worldPos, std::vector<std::vector<Tile>>& tiles);
    /**
     * @brief Handle the mouse click
     *
     * @param window
     * @param worldPos
     * @param tiles
     * @param selectedTile
     * @param selectedCharacter
     * @param menu
     * @param tileSelected
     * @param chracterSelected
     * @param resources
     * @param characters
     * @param client
     */
    void handleMouseClick(sf::RenderWindow& window, const sf::Vector2f& worldPos, std::vector<std::vector<Tile>>& tiles, Tile*& selectedTile, const Character*& selectedCharacter, Menu& menu, bool& tileSelected, bool& chracterSelected,const std::vector<Resources>& resources, const std::vector<Character>& characters, Client& client);
    /**
     * @brief Handle all mouse events
     *
     * @param window
     * @param view
     * @param event
     * @param tiles
     * @param selectedTile
     * @param selectedCharacter
     * @param menu
     * @param tileSelected
     * @param chracterSelected
     * @param camera
     * @param resources
     * @param characters
     * @param client
     */
    void handleAllMouseEvents(sf::RenderWindow& window, sf::View& view, const sf::Event& event, std::vector<std::vector<Tile>>& tiles, Tile*& selectedTile, const Character*& selectedCharacter, Menu& menu, bool& tileSelected, bool& chracterSelected, Camera& camera, const std::vector<Resources>& resources, const std::vector<Character>& characters, Client& client);
};

#endif /* !MOUSE_HPP_ */
