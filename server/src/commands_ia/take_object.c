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
 * @brief Take an object from the map.
 *
 * @param server
 * @param player
 * @param params
*/
void command_take(server_t *server, player_t *player, const char *params)
{
    tile_type_t object_type = get_object(params);
    int *ressource = NULL;
    char message[1024];

    if (object_type == ITEM_COUNT) {
        dprintf(player->fd, "ko\n");
        return;
    }
    ressource = server->map.tiles[player->y][player->x].resources[object_type];
    if (ressource[0] == 0) {
        dprintf(player->fd, "ko\n");
        return;
    }
    if (player->is_elevating == false) {
        player->inventory.resources[object_type][0] += 1;
        server->map.tiles[player->y][player->x].resources[object_type][0] -= 1;
        snprintf(message, 1024, "pgt %d %d\n", player->fd, object_type);
        send_graphical(server, message);
        dprintf(player->fd, "ok\n");
    }
}
