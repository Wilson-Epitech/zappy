/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** ppo
*/

#include <stdio.h>
#include <stdlib.h>

#include "server.h"

void command_ppo(server_t *server, player_t *player, const char *params)
{
    char **array = word_array_delim(params, " ");
    int size = get_array_size(array);
    player_t target = server->players[atoi(params)];

    if (size != 1) {
        dprintf(player->fd, "spb\n");
        return;
    }
    dprintf(player->fd, "ppo %d %d %d %d\n",
        target.fd, target.x, target.y, target.orientation);
}
