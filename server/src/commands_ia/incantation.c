/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** incantation
*/

#include "server.h"
#include <string.h>
#include <stdio.h>

static void level_one(server_t *server, player_t *player)
{
    if (server->players_connected >= 1 && player->inventory.linemate >= 1) {
        player->level += 1;
    } else {
        dprintf(player->fd, "ko\n");
    }
}

static void start_incantation(server_t *server, player_t *player)
{
    switch (player->level) {
        case 1:
            level_one(server, player);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            break;
    }
}

/**
 * @brief Executes the incantation command
 * @param server
 * @param player
 * @param command
*/
void command_incantation(server_t *server, player_t *player,
    const char *params)
{
    if (strcmp(params, "\0") != 0) {
        dprintf(player->fd, "ko\n");
        return;
    }
    if (player->is_elevating == false) {
        start_incantation(server, player);
    }
}
