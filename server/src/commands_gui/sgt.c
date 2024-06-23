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

/**
 * @brief Send the time unit to the player.
 *
 * @param server The server instance.
 * @param player The player instance.
 * @param params The command.
 */
void command_sgt(server_t *server, player_t *player, const char *params)
{
    char *answer;

    if (strcmp(params, "") != 0)
        return;
    answer = malloc(sizeof(char) * 100);
    sprintf(answer, "sgt %ld\n", server->opt->freq);
    send(player->fd, answer, strlen(answer), 0);
    free(answer);
}
