/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** death
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

/**
 * @brief Check if a player is dead.
 * @param server The server instance.
*/
void death_player(server_t *server)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].inventory.food <= 0) {
            dprintf(server->players[i].fd, "dead\n");
            close(server->players[i].fd);
            memset(&server->players[i], 0, sizeof(player_t));
        }
    }
    printf("death\n");
}
