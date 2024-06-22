/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** is_player_connect
*/

#include "server.h"

/**
 * @brief Check if a player is connected by his fd.
 *
 * @param server
 * @param fd
 * @return true
 * @return false
*/

bool is_player_connect(server_t *server, int fd)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == fd && server->players[i].fd != 0
            && server->players[i].team_id > -1) {
            return true;
        }
    }
    return false;
}
