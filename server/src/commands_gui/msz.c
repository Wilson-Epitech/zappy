/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** msz
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

void command_msz(server_t *server, player_t *player, const char *params)
{
    char *answer = malloc(sizeof(char) * 100);

    (void)player;
    (void)params;
    sprintf(answer, "----------msz----------\nMap width: %ld\nMap height: %ld"
        "\n-----------------------\n", server->opt->map_width,
        server->opt->map_height);
    send(player->fd, answer, strlen(answer), 0);
    free(answer);
}
