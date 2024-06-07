/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** sgt
*/

#include <stdio.h>
#include <time.h>
#include "server.h"

void command_sgt(server_t *server, player_t *player, const char *params)
{
    (void)player;
    (void)params;
    printf("----------sgt----------\nTime elapsed since start: %f\n-----------"
    "--------------\n", difftime(time(NULL), server->opt->start_time));
}
