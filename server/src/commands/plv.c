/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** plv
*/

#include "server.h"

#include <stdio.h>
#include <stdlib.h>

void command_plv(server_t *server, player_t *player, const char *params)
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
    dprintf(player->fd, "plv %d %d\n", player->fd , player->level);
}
