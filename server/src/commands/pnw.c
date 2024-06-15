/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** pnw
*/

#include "server.h"
#include <stdio.h>

/**
 * @brief Executes the pnw command and send a message when a player connects
 *
 * @param params
*/

void command_pnw(server_t *server, int client_fd)
{
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (server->players[i].team_id == -2) {
            dprintf(i, "pnw %d %d %d %d %d %s\n",
            i,
            server->players[client_fd].x,
            server->players[client_fd].y,
            server->players[client_fd].orientation,
            server->players[client_fd].level,
            server->players[client_fd].team_name);
        }
    }
}
