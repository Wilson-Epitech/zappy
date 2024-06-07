/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** init_server
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void setup_socket(server_t *server)
{
    int opt = 1;

    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->fd == -1) {
        perror("socket");
        exit(FAILURE);
    }
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(FAILURE);
    }
    server->addr.sin_family = AF_INET;
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->addr.sin_port = htons(server->port);
}

static void bind_socket(server_t *server)
{
    if (bind(server->fd, (struct sockaddr*)&server->addr,
        sizeof(server->addr)) == -1) {
        perror("bind");
        close(server->fd);
        exit(FAILURE);
    }
}

static void listen_socket(server_t *server)
{
    if (listen(server->fd, MAX_CLIENTS) == -1) {
        perror("listen");
        close(server->fd);
        exit(FAILURE);
    }
}

void init_server(server_t *server, options_t *opt)
{
    server->port = opt->port;
    server->opt = opt;
    setup_socket(server);
    bind_socket(server);
    listen_socket(server);
    FD_ZERO(&server->read_fd);
    FD_ZERO(&server->write_fd);
    FD_SET(server->fd, &server->read_fd);
    printf("Server initialized on port %d\n", server->port);
}
