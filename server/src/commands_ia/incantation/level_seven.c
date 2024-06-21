/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** level_seven
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Level seven incantation.
 * This function checks if the player has the required resources to level up.
 * @param server The server instance.
 * @param player The player that sent the command.
*/
void level_seven(server_t *server, player_t *player)
{
    if (server->players_connected >= 6 && player->inventory.linemate >= 2
        && player->inventory.deraumere >= 2 && player->inventory.sibur >= 2
        && player->inventory.mendiane >= 2 && player->inventory.phiras >= 2
        && player->inventory.thystame >= 1) {
        player->level += 1;
        player->inventory.linemate -= 2;
        player->inventory.deraumere -= 2;
        player->inventory.sibur -= 2;
        player->inventory.mendiane -= 2;
        player->inventory.phiras -= 2;
        player->inventory.thystame -= 1;
    } else {
        dprintf(player->fd, "ko\n");
    }
}
