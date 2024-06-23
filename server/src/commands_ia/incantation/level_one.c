/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** level_one
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Check if the player can level up to level 1.
 * @param server The server instance.
 * @param player The player instance.
*/
void level_one(server_t *server, player_t *player)
{
    if (server->players_connected >= 1
        && server->map.tiles[player->y][player->x].linemate >= 1) {
        player->level += 1;
        server->map.tiles[player->y][player->x].resources[LINEMATE][0] -= 1;
        dprintf(player->fd, "Elevation underway\nCurrent level: %d\n",
            player->level);
    } else {
        dprintf(player->fd, "ko\n");
    }
}
