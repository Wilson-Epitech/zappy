/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** teleport
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

static void set_coords(server_t *server, int fd, int x, int y)
{
    char message[1024] = {0};

    if (is_player_connect(server, fd) == false) {
        printf("Player not found\n");
        return;
    }
    server->players[fd].x = x;
    server->players[fd].y = y;
    sprintf(message, "ppo %d %d %d %d\n", fd, x, y,
        server->players[fd].orientation);
    send_graphical(server, message);
    printf("Player position changed to %d %d\n", x, y);
}

/**
 * @brief Teleport a player to a specific position.
 *
 * @param server
 * @param player
 * @param args
*/
void command_teleport(server_t *server, player_t *player, char **args)
{
    int fd = 0;
    int x = 0;
    int y = 0;

    if (get_array_size(args) != 4) {
        dprintf(player->fd, "Wrong Arguments\n");
        return;
    }
    fd = atoi(args[1]);
    x = atoi(args[2]);
    y = atoi(args[3]);
    if (x < 0 || y < 0 || x >= (int)server->map.width
        || y >= (int)server->map.height || fd <= 0) {
        dprintf(player->fd, "Invalid position\n");
        return;
    }
    set_coords(server, fd, x, y);
}
