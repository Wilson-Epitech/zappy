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
    if (server->players_connected >= 2 && player->inventory.linemate >= 1
        && player->inventory.deraumere >= 1 && player->inventory.sibur >= 1) {
        player->level += 1;
        player->inventory.linemate -= 1;
        player->inventory.deraumere -= 1;
        player->inventory.sibur -= 1;
    } else {
        dprintf(player->fd, "ko\n");
    }
}
