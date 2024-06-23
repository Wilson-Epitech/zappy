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
 * @param server
 * @param client_fd
*/
void command_pnw(server_t *server, int client_fd)
{
    char message[1024];

    snprintf(message, 1024, "pnw %d %d %d %d %d %s\n",
        client_fd,
        server->players[client_fd].x,
        server->players[client_fd].y,
        server->players[client_fd].orientation,
        server->players[client_fd].level,
        server->players[client_fd].team_name);
    send_graphical(server, message);
}
