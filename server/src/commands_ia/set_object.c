/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** set_object
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Get the item object
 *
 * @param params
 * @return tile_type_t
*/
static tile_type_t get_item(const char *params)
{
    const char *item_names[ITEM_COUNT] = {
    "food", "linemate", "deraumere", "sibur",
    "mendiane", "phiras", "thystame"
    };

    if (strcmp(params, "\0") == 0)
        return ITEM_COUNT;
    for (int i = 0; i < ITEM_COUNT - 2; ++i) {
        if (strcmp(params, item_names[i]) == 0) {
            return (tile_type_t)i;
        }
    }
    return ITEM_COUNT;
}

/**
 * @brief Set an object on the map.
 *
 * @param server
 * @param player
 * @param params
*/
void command_set(server_t *server, player_t *player, const char *params)
{
    tile_type_t object_type = get_item(params);
    int *ressources = NULL;
    char message[1024];

    if (object_type == ITEM_COUNT) {
        dprintf(player->fd, "ko\n");
        return;
    }
    ressources = player->inventory.resources[object_type];
    if (ressources[0] == 0) {
        dprintf(player->fd, "ko\n");
        return;
    }
    player->inventory.resources[object_type][0] -= 1;
    server->map.tiles[player->y][player->x].resources[object_type][0] += 1;
    snprintf(message, 1024, "pdr %d %d\n", player->fd, object_type);
    send_graphical(server, message);
    dprintf(player->fd, "ok\n");
}
