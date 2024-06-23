/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** level_four
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Check if the player can level up to level 4.
 * @param server The server_t struct.
 * @param player The player_t struct.
*/
void level_four(server_t *server, player_t *player)
{
    if (server->players_connected >= 4 && player->inventory.linemate >= 1
        && player->inventory.deraumere >= 1 && player->inventory.sibur >= 2
        && player->inventory.phiras >= 1) {
        player->level += 1;
        player->inventory.linemate -= 1;
        player->inventory.deraumere -= 1;
        player->inventory.sibur -= 2;
        player->inventory.phiras -= 1;
        dprintf(player->fd, "Elevation underway\nCurrent level: %d\n",
            player->level);
    } else {
        dprintf(player->fd, "ko\n");
    }
}
