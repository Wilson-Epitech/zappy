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
    int player_nb = 0;

    if (size != 1) {
        dprintf(player->fd, "spb\n");
        return;
    }
    player_nb = atoi(array[0]);
    if (player_nb != player->fd) {
        dprintf(player->fd, "spb\n");
        return;
    }
    dprintf(player->fd, "ppo %d %d %d %d\n",
        player->fd, player->x, player->y, player->orientation);
}
