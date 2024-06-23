/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** init_player
*/

#include "server.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * @brief Set the player's team
 * @param server
 * @param client_fd The client's fd
 * @param i The team's id
*/
void set_player_team(server_t *server, int client_fd, int i)
{
    server->players[client_fd].team_id = i;
    server->players[client_fd].team_name =
        malloc(sizeof(char) * (strlen(server->opt->names[i]) + 1));
    strcpy(server->players[client_fd].team_name,
        server->opt->names[i]);
    dprintf(client_fd, "%d\n%ld %ld\n",
        free_slots(server, &server->players[client_fd]),
        server->opt->map_height, server->opt->map_width);
}

/**
 * @brief Init default value of the player
 * @param player
 * @param fd The client's fd
*/
void init_player(server_t *server, player_t *player, int fd)
{
    srand(time(NULL));
    player[fd].team_id = -1;
    player[fd].level = 1;
    player[fd].x = rand() % (int)server->opt->map_width;
    player[fd].y = rand() % (int)server->opt->map_height;
    memset(player[fd].team_name, 0, 0);
    player[fd].orientation = (rand() % 4) + 1;
    player[fd].fd = fd;
    player[fd].is_elevating = false;
    player[fd].is_immortal = false;
    player[fd].time = time(NULL);
    player[fd].is_dead = false;
    init_inventory(player, fd);
}
