/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** tiles
*/

#ifndef TILES_H_
    #define TILES_H_

/**
 * @brief Enum to handle tile types
 */
typedef enum tile_type_e {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    PLAYER,
    EGG,
    ITEM_COUNT
} tile_type_t;

/**
 * @brief Structure to handle tiles
 *
 * @param food Number of food
 * @param linemate Number of linemate
 * @param deraumere Number of deraumere
 * @param sibur Number of sibur
 * @param mendiane Number of mendiane
 * @param phiras Number of phiras
 * @param thystame Number of thystame
 * @param player Number of players
 * @param egg Number of eggs
 * @param resources Array of resources
 * @return tile_t
 */
typedef struct tile_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int player;
    int egg;
    int *resources[ITEM_COUNT];
} tile_t;

#endif /* !TILES_H_ */
