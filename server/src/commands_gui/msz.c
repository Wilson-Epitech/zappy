/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** msz
*/

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void command_msz(server_t *server, player_t *player, const char *)
{
    char *answer = malloc(sizeof(char) * 100);

    sprintf(answer, "msz %ld %ld\n", server->opt->map_width,
        server->opt->map_height);
    send(player->fd, answer, strlen(answer), 0);
    free(answer);
}
