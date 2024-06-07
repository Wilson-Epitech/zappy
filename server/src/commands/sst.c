/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** sst
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "server.h"

void command_sst(server_t *server, player_t *player, const char *params)
{
    int time_change = atoi(params);

    (void)player;
    (void)params;
    server->opt->start_time = server->opt->start_time + difftime(time(NULL),
        server->opt->start_time) - time_change;
    printf("----------sst----------\n");
    printf("Time set to: %d\n", time_change);
    printf("----------------------\n");
}
