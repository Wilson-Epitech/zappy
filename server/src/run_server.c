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
#include <stdbool.h>
#include <time.h>

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

static void distribute_remaining_resources(server_t *server,
    int remaining, int resource_index)
{
    int i = 0;
    int j = 0;

    srand(time(NULL));
    while (remaining > 0) {
        i = rand() % server->opt->map_height;
        j = rand() % server->opt->map_width;
        switch (resource_index) {
        case 0:
            server->map.tiles[i][j].food += 1;
            break;
        case 1:
            server->map.tiles[i][j].linemate += 1;
            break;
        case 2:
            server->map.tiles[i][j].deraumere += 1;
            break;
        case 3:
            server->map.tiles[i][j].sibur += 1;
            break;
        case 4:
            server->map.tiles[i][j].mendiane += 1;
            break;
        case 5:
            server->map.tiles[i][j].phiras += 1;
            break;
        case 6:
            server->map.tiles[i][j].thystame += 1;
            break;
        default:
            break;
    }
        remaining--;
    }
}

void refill_map(server_t *server, time_t *start_time)
{
    time_t current_time = time(NULL);
    time_t diff = current_time - *start_time;
    int total_tiles = server->opt->map_width * server->opt->map_height;

    if (diff < (long int)(20 / server->opt->freq))
        return;

    int food_quantity = total_tiles * 0.5;
    int linemate_quantity = total_tiles * 0.3;
    int deraumere_quantity = total_tiles * 0.15;
    int sibur_quantity = total_tiles * 0.1;
    int mendiane_quantity = total_tiles * 0.1;
    int phiras_quantity = total_tiles * 0.08;
    int thystame_quantity = total_tiles * 0.05;

    for (size_t i = 0; i < server->opt->map_height; i++) {
        for (size_t j = 0; j < server->opt->map_width; j++) {
            server->map.tiles[i][j].food = food_quantity / total_tiles;
            server->map.tiles[i][j].linemate = linemate_quantity / total_tiles;
            server->map.tiles[i][j].deraumere = deraumere_quantity / total_tiles;
            server->map.tiles[i][j].sibur = sibur_quantity / total_tiles;
            server->map.tiles[i][j].mendiane = mendiane_quantity / total_tiles;
            server->map.tiles[i][j].phiras = phiras_quantity / total_tiles;
            server->map.tiles[i][j].thystame = thystame_quantity / total_tiles;
        }
    }
    distribute_remaining_resources(server, food_quantity % total_tiles, 0);
    distribute_remaining_resources(server, linemate_quantity % total_tiles, 1);
    distribute_remaining_resources(server,
        deraumere_quantity % total_tiles, 2);
    distribute_remaining_resources(server, sibur_quantity % total_tiles, 3);
    distribute_remaining_resources(server, mendiane_quantity % total_tiles, 4);
    distribute_remaining_resources(server, phiras_quantity % total_tiles, 5);
    distribute_remaining_resources(server, thystame_quantity % total_tiles, 6);
    *start_time = current_time;
}

/**
 * @brief Runs the server.
 *
 * @param server The server instance.
 */
void run_server(server_t *server, tile_density_t *)
{
    fd_set read_fds = {0};
    time_t start_time = time(NULL);

    printf("Server running on port %d\n", server->port);
    while (server->is_end == false) {
        read_fds = server->read_fd;
        check_sockets(server, &read_fds);
        handle_read_fds(server, &read_fds);
        handle_command_queue(server->queue, server, &server->players
            [server->queue->commands[server->queue->front].client_fd]);
        decrement_food(server);
        death_player(server);
        refill_map(server, &start_time);
    }
}
