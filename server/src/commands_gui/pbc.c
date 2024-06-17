/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** pbc
*/

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Sends a message to all GUI clients.
 * 
 * This function sends a message to all GUI clients.
 * 
 * @param server The server instance.
 * @param player The array of players.
 * @param params The parameters sent with the command. This should
 * be the message to send.
*/
void command_pbc(server_t *server, player_t *player, const char *params)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].id == -2) {
            dprintf(server->players[i].fd, "pbc %d %s\n", player->fd, params);
        }
    }
}