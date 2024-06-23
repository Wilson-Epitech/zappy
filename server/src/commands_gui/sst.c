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

/**
 * @brief Send the time unit to the player.
 * 
 * @param server The server instance.
 * @param player The player instance.
 * @param params The command.
 */
void command_sst(server_t *server, player_t *player, const char *params)
{
    int time_change;
    char *answer;

    if (strcmp(params, "") == 0)
        return;
    if (strtok(strtok(NULL, " "), " ") != NULL)
        return;
    if (atoi(params) < 0)
        return;
    time_change = atoi(params);
    answer = malloc(sizeof(char) * 100);
    server->opt->freq = time_change;
    sprintf(answer, "sst %d\n", time_change);
    send(player->fd, answer, strlen(answer), 0);
    free(answer);
}
