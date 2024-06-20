/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** take_object
*/

#include "server.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief Get the object type
 *
 * @param params
 * @return tile_type_t
*/
static tile_type_t get_object_type(const char *params)
{
    const char *item_names[ITEM_COUNT] = {
    "food", "linemate", "deraumere", "sibur",
    "mendiane", "phiras", "thystame", "player", "egg"
    };

    if (strcmp(params, "\0") == 0)
        return ITEM_COUNT;
    for (int i = 0; i < ITEM_COUNT; ++i) {
        if (strcmp(params, item_names[i]) == 0) {
            return (tile_type_t)i;
        }
    }
    return ITEM_COUNT;
}

/**
 * @brief Take an object from the map.
 *
 * @param server
 * @param player
 * @param params
*/
void command_take(server_t *server, player_t *player, const char *params)
{
    tile_type_t object_type = get_object_type(params);
    int *ressources = NULL;
    char message[1024];

    if (object_type == ITEM_COUNT) {
        dprintf(player->fd, "ko\n");
        return;
    }
    ressources =
        server->map.tiles[player->y][player->x].resources[object_type];
    if (ressources[0] == 0) {
        dprintf(player->fd, "ko\n");
        return;
    }
    player->inventory.resources[object_type][0] += 1;
    server->map.tiles[player->y][player->x].resources[object_type][0] -= 1;
    snprintf(message, 1024, "pgt %d %d\n", player->fd, object_type);
    send_graphical(server, message);
    dprintf(player->fd, "ok\n");
}
