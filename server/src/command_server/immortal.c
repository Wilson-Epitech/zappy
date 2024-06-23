/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** immortal
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Make a player immortal.
 *
 * @param server
 * @param player
 * @param args
*/
void command_immortal(server_t *server, player_t *player, char **args)
{
    int fd = 0;
    int immortal = 0;

    if (get_array_size(args) != 3) {
        dprintf(player->fd, "Wrong Arguments\n");
        return;
    }
    fd = atoi(args[1]);
    immortal = atoi(args[2]);
    if (fd <= 0 || immortal < 0 || immortal > 1) {
        dprintf(player->fd, "Wrong fd\n");
        return;
    }
    if (is_player_connect(server, fd) == false) {
        dprintf(player->fd, "Player not found\n");
        return;
    }
    server->players[fd].is_immortal = immortal;
    printf("Player immortal changed to %d\n", immortal);
}
