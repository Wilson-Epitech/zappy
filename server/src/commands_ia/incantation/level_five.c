/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** level_five
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Level five incantation.
 * This function checks if the player has the required resources to level up.
 * @param server The server instance.
 * @param player The player that sent the command.
*/
void level_five(server_t *server, player_t *player)
{
    if (server->players_connected >= 4 && player->inventory.linemate >= 1
        && player->inventory.deraumere >= 2 && player->inventory.sibur >= 1
        && player->inventory.mendiane >= 3) {
        player->level += 1;
        player->inventory.linemate -= 1;
        player->inventory.deraumere -= 2;
        player->inventory.sibur -= 1;
        player->inventory.mendiane -= 3;
    } else {
        dprintf(player->fd, "ko\n");
    }
}
