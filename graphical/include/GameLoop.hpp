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
#include "../include/Tile.h"
#include "../include/Camera.hpp"
#include "../include/Parallax.hpp"
#include "../include/Menu.hpp"
#include "../include/Mouse.hpp"
#include "../include/Music.hpp"
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

const int boardWidth = 10;
const int boardHeight = 10;

void gameLoop();

#endif /* !GAMELOOP_HPP */
