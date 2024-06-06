/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** run_server
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void check_sockets(server_t *server, fd_set *read_fds)
{
    if (select(FD_SETSIZE, read_fds, NULL, NULL, NULL) == -1) {
        perror("select");
        close(server->fd);
        exit(FAILURE);
    }
}

void chose_client(server_t *server, int i)
{
    if (i == server->fd) {
        accept_client(server);
    } else {
        handle_client(server, i);
    }
}

static void handle_read_fds(server_t *server, fd_set *read_fds)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, read_fds)) {
            chose_client(server, i);
        }
    }
}

void run_server(server_t *server)
{
    fd_set read_fds = {0};

    printf("Server running on port %d\n", server->port);
    while (1) {
        read_fds = server->read_fd;
        check_sockets(server, &read_fds);
        handle_read_fds(server, &read_fds);
    }
}
