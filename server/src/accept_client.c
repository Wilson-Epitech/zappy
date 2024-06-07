/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** accept_client
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Accepts a new client connection.
 * 
 * If a client is trying to connect, this function accepts the connection,
 * assigns the client to an available slot in the server's players array,
 * and adds the client's file descriptor to the server's read file descriptor set.
 * 
 * @param server The server instance.
 */
void accept_client(server_t *server)
{
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd =
        accept(server->fd, (struct sockaddr*)&client_addr, &client_len);

    if (client_fd == -1) {
        perror("accept");
        return;
    }
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == 0) {
            server->players[i].fd = client_fd;
            FD_SET(client_fd, &server->read_fd);
            printf("Client connected: %d\n", client_fd);
            break;
        }
    }
}
