/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** broadcast
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Broadcasts a message to all players.
 *
 * This function sends a message to all players in the server.
 *
 * @param server The server instance.
 * @param player The array of players.
 * @param params The parameters sent with the command. This should be
 * the file descriptor of the player.
 *
*/
void command_broadcast(server_t *server, player_t *player, const char *params)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].id > -1 &&
            server->players[i].fd != player->fd) {
            dprintf(server->players[i].fd, "message %d, %s\n",
            player->fd, params);
        }
    }
    dprintf(player->fd, "ok\n");
}
