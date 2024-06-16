/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** plv
*/

#include "server.h"

#include <stdio.h>

void command_plv(server_t *server, player_t *player, const char *params)
{
    char **array = word_array_delim(params, " ");
    int size = get_array_size(array);

    if (size != 1)
        dprintf(player->fd, "spb\n");
    else
        dprintf(player->fd, "plv %d %d\n", player->fd , player->level);
}
