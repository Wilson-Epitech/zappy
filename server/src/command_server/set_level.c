/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** set_level
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Set the level of a player.
 *
 * @param server
 * @param player
 * @param args
*/
void command_set_level(server_t *server, player_t *player, char **args)
{
    int fd = 0;
    int level = 0;

    if (get_array_size(args) != 3) {
        dprintf(player->fd, "Wrong Arguments\n");
        return;
    }
    fd = atoi(args[1]);
    level = atoi(args[2]);
    if (fd <= 0 || level <= 0 || level > 8) {
        dprintf(player->fd, "Wrong fd or level\n");
        return;
    }
    if (is_player_connect(server, fd) == false) {
        dprintf(player->fd, "Player not found\n");
        return;
    }
    server->players[fd].level = level;
    printf("Player level changed to %d\n", level);
}
