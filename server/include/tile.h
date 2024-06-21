/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** tiles
*/

#ifndef TILES_H_
    #define TILES_H_

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
