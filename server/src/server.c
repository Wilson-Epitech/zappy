/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** server
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

static void clear_client(server_t *server, int client_fd)
{
    close(client_fd);
    FD_CLR(client_fd, &server->read_fd);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == client_fd) {
            server->players[i].fd = 0;
            break;
        }
    }
}

static void read_client_data(server_t *server,
    int client_fd, ssize_t, char *buffer)
{
    printf("Received from %d: %s\n", client_fd, buffer);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == client_fd) {
            process_command(server, &server->players[i], buffer);
            break;
        }
    }
}

void handle_client(server_t *server, int client_fd)
{
    char buffer[1024] = {0};
    ssize_t bytes_read = 0;

    bytes_read = read(client_fd, buffer, sizeof(buffer));
    if (bytes_read <= 0) {
        if (bytes_read == 0)
            printf("Client disconnected: %d\n", client_fd);
        else
            perror("read");
        clear_client(server, client_fd);
    } else {
        buffer[bytes_read - 1] = '\0';
        read_client_data(server, client_fd, bytes_read, buffer);
    }
}

void cleanup_server(server_t *server)
{
    close(server->fd);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd != 0) {
            close(server->players[i].fd);
        }
    }
    printf("Server cleaned up.\n");
}
