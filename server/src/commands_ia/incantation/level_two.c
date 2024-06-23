/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** level_two
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Check if the player can level up to level 2.
 * @param server The server instance.
 * @param player The player instance.
*/
void level_two(server_t *server, player_t *player)
{
    int player_fd = retreive_player(server, player->x, player->y);

    if (server->players_connected >= 2
        && server->map.tiles[player->y][player->x].player >= 2
        && server->players[player_fd].level == player->level
        && server->map.tiles[player->y][player->x].linemate >= 1
        && server->map.tiles[player->y][player->x].deraumere >= 1
        && server->map.tiles[player->y][player->x].sibur >= 1) {
        player->level += 1;
        server->players[player_fd].level += 1;
        server->map.tiles[player->y][player->x].resources[LINEMATE][0] -= 1;
        server->map.tiles[player->y][player->x].resources[DERAUMERE][0] -= 1;
        server->map.tiles[player->y][player->x].resources[SIBUR][0] -= 1;
        dprintf(player->fd, "Elevation underway\nCurrent level: %d\n",
            player->level);
    } else {
        dprintf(player->fd, "ko\n");
    }
}
