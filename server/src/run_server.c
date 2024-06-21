/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** run_server
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

/**
 * @brief Checks the sockets for any activity.
 *
 * @param server The server instance.
 * @param read_fds The set of file descriptors to check.
 */
static void check_sockets(server_t *server, fd_set *read_fds)
{
    if (select(FD_SETSIZE, read_fds, NULL, NULL, &server->tv) == -1) {
        perror("select");
        close(server->fd);
        exit(FAILURE);
    }
}

/**
 * @brief Chooses the client to handle based on the file descriptor.
 *
 * @param server The server instance.
 * @param i The file descriptor.
 */
void chose_client(server_t *server, int i)
{
    if (i == server->fd) {
        accept_client(server);
    } else {
        handle_client(server, i);
    }
}

/**
 * @brief Handles the ready file descriptors.
 *
 * @param server The server instance.
 * @param read_fds The set of ready file descriptors.
 */
static void handle_read_fds(server_t *server, fd_set *read_fds)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, read_fds)) {
            chose_client(server, i);
        }
    }
}

void decrement_player_food(server_t *server, int i)
{
    if (server->players[i].inventory.food > 0 && server->players[i].fd != 0
        && server->players[i].team_id != -2) {
        server->players[i].inventory.food--;
    }
}

/**
 * @brief Decrements the food of all players connected.
 *
 * @param server The server instance.
 */
void decrement_food(server_t *server)
{
    static time_t end;
    double elapsed;

    end = time(NULL);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == 0 || server->players[i].team_id == -1 ||
            server->players[i].team_id == -2) {
            continue;
        }
        elapsed = difftime(end, server->players[i].time);
        if (elapsed >= (126.0 / server->opt->freq)) {
            server->players[i].time = time(NULL);
            decrement_player_food(server, i);
        }
    }
}

/**
 * @brief Runs the server.
 *
 * @param server The server instance.
 */
void run_server(server_t *server)
{
    fd_set read_fds = {0};

    printf("Server running on port %d\n", server->port);
    while (1) {
        read_fds = server->read_fd;
        check_sockets(server, &read_fds);
        handle_read_fds(server, &read_fds);
        handle_command_queue(server->queue, server, &server->players
            [server->queue->commands[server->queue->front].client_fd]);
        decrement_food(server);
        death_player(server);
    }
}
