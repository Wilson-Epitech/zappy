/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** sst
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

void command_sst(server_t *server, player_t *player, const char *params)
{
    int time_change = atoi(params);
    char *answer = malloc(sizeof(char) * 100);

    server->opt->start_time = server->opt->start_time + difftime(time(NULL),
        server->opt->start_time) - time_change;
    sprintf(answer, "sst %d\n", time_change);
    send(player->fd, answer, strlen(answer), 0);
    free(answer);
}
