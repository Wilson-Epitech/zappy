/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** send_graphical
*/

#include "server.h"
#include <stdio.h>

/**
 * @brief Send a message to all graphical clients
 * @param server
 * @param message
*/
void send_graphical(server_t *server, const char *message)
{
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (server->players[i].team_id == -2) {
            dprintf(i, "%s", message);
        }
    }
}
