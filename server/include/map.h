/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_
    #include "tile.h"

/**
 * @brief Structure to handle map
 * 
 * @param tiles Array of tiles
 * @param width Width of the map
 * @param height Height of the map
 * @return map_t
 */
typedef struct map_s {
    tile_t **tiles;
    size_t width;
    size_t height;
} map_t;

#endif /* !MAP_H_ */
