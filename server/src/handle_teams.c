/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** handle_teams
*/

#include "server.h"
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
