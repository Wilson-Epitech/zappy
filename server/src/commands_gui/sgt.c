/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** sgt
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

void command_sgt(server_t *server, player_t *player, const char *)
{
    char *answer = malloc(sizeof(char) * 100);

    sprintf(answer, "sgt %f\n", difftime(time(NULL), server->opt->start_time));
    send(player->fd, answer, strlen(answer), 0);
    free(answer);
}
