/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** handle_teams
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Increment all players connected and add players by team
 *
 * @param server
 * @param name
 * @param index
*/
void handle_teams(server_t *server, char *name, int index)
{
    server->teams[index].name =
        malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(server->teams[index].name, name);
    ++server->teams[index].player_count;
    ++server->players_connected;
}

/**
 * @brief Handle player disconnect
 *
 * @param server
 * @param client_fd
 */
void handle_disconnect(server_t *server, int client_fd)
{
    printf("Client disconnected: %d\n", client_fd);
    for (int i = 0; i < server->players_connected; ++i) {
        if (strcmp(server->teams[i].name, server->players[client_fd].team_name)
            == 0) {
            --server->teams[i].player_count;
            break;
        }
    }
    --server->players_connected;
}
