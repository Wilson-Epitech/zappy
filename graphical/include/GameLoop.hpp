/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** GameLoop
*/

#ifndef GAMELOOP_HPP_
#define GAMELOOP_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tile.hpp"
#include "Camera.hpp"
#include "Parallax.hpp"
#include "Menu.hpp"
#include "Mouse.hpp"
#include "Music.hpp"
#include "Character.hpp"
#include "Client.hpp"
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <iostream>
#include <ctime>

/**
 * @brief 
 * 
 * @param window 
 * @param tiles 
 */
void drawBoard(sf::RenderWindow& window, const std::vector<std::vector<Tile>>& tiles);
/**
 * @brief 
 * 
 * @param tiles 
 */
void updateBoard(std::vector<std::vector<Tile>>& tiles);
/**
 * @brief 
 * 
 * @param client 
 */
void gameLoop(Client& client);
/**
 * @brief 
 * 
 * @param window 
 * @param resources 
 */
void printCharacters(const std::vector<Character>& characters);

#endif /* !GAMELOOP_HPP */
