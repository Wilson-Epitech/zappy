/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** food_gestion
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "server.h"

static void decrement_player_food(server_t *server, int i)
{
    if (server->players[i].inventory.food > 0 && server->players[i].fd != 0
        && server->players[i].team_id != -2) {
        server->players[i].inventory.food--;
    }
}

/**
 * @brief Decrements the food of all players connected.
 *
 * @param server The server instance.
 */
void decrement_food(server_t *server)
{
    static time_t end;
    double elapsed;

    end = time(NULL);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == 0 || server->players[i].team_id == -1 ||
            server->players[i].team_id == -2) {
            continue;
        }
        elapsed = difftime(end, server->players[i].time);
        if (elapsed >= (126.0 / server->opt->freq)) {
            server->players[i].time = time(NULL);
            decrement_player_food(server, i);
        }
    }
}
