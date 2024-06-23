/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** level_six
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Level six incantation.
 * This function checks if the player has the required resources to level up.
 * @param server The server instance.
 * @param player The player that sent the command.
*/
void level_six(server_t *server, player_t *player)
{
    if (server->players_connected >= 6 && player->inventory.linemate >= 1
        && player->inventory.deraumere >= 2 && player->inventory.sibur >= 3
        && player->inventory.phiras >= 1) {
        player->level += 1;
        player->inventory.linemate -= 1;
        player->inventory.deraumere -= 2;
        player->inventory.sibur -= 3;
        player->inventory.phiras -= 1;
        dprintf(player->fd, "Elevation underway\nCurrent level: %d\n",
            player->level);
    } else {
        dprintf(player->fd, "ko\n");
    }
}
