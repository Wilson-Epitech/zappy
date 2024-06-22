/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** get_object
*/

#include "server.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief Get the object object
 *
 * @param params
 * @return tile_type_t
*/
tile_type_t get_object(const char *params)
{
    const char *item_names[ITEM_COUNT - 1] = {
        "food", "linemate", "deraumere", "sibur",
        "mendiane", "phiras", "thystame"
    };

    if (strcmp(params, "\0") == 0)
        return ITEM_COUNT;
    for (size_t i = 0; i < ITEM_COUNT - 2; ++i) {
        if (strcmp(params, item_names[i]) == 0) {
            return (tile_type_t)i;
        }
    }
    return ITEM_COUNT;
}
