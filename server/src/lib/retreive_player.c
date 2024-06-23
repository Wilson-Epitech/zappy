/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** retreive_player
*/

#include "server.h"

/**
 * @brief Retreive the player by his position.
 *
 * @param server The server instance.
 * @param x The x position.
 * @param y The y position.
 * @return int The player's fd.
 */
int retreive_player(server_t *server, int x, int y)
{
    for (int i = 0; i < server->players_connected; i++) {
        if (server->players[i].x == x && server->players[i].y == y)
            return server->players[i].fd;
    }
    return -1;
}
