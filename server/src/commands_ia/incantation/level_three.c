/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** level_three
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Check if the player can level up to level 3.
 * @param server The server_t struct.
 * @param player The player_t struct.
*/
void level_three(server_t *server, player_t *player)
{
    if (server->players_connected >= 2 && player->inventory.linemate >= 2
        && player->inventory.phiras >= 2 && player->inventory.sibur >= 1) {
        player->level += 1;
        player->inventory.linemate -= 2;
        player->inventory.phiras -= 2;
        player->inventory.sibur -= 1;
    } else {
        dprintf(player->fd, "ko\n");
    }
}
