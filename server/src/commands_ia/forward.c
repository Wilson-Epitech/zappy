/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** forward
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief PLayer forward 1 tiles.
 * @param server The server instance.
 * Not used in this function but included
 * for consistency with other command handlers.
 * @param player The array of players.
 * @param params The parameters sent with the command.
 * This should be the file descriptor of the player.
*/
static void move_forward(server_t *server, player_t *player)
{
    if (player->orientation == 1) {
        player->y =
            (player->y - 1 + server->opt->map_width) % server->opt->map_width;
        return;
    }
    if (player->orientation == 2) {
        player->x = (player->x + 1) % server->opt->map_height;
        return;
    }
    if (player->orientation == 3) {
        player->y = (player->y + 1) % server->opt->map_width;
        return;
    }
    if (player->orientation == 4) {
        player->x =
        (player->x - 1 + server->opt->map_height) % server->opt->map_height;
        return;
    }
}

/**
 * @brief Executes the forward command.
 * @param server The server instance.
 * @param player The array of players.
 * @param params The parameters sent with the command.
 * This should be the file descriptor of the player.
*/
void command_forward(server_t *server, player_t *player, const char *params)
{
    char message[1024] = {0};

    if (strcmp(params, "\0") == 1) {
        dprintf(player->fd, "ko\n");
        return;
    }
    if (player->is_elevating == false) {
        move_forward(server, player);
        dprintf(player->fd, "ok\n");
        snprintf(message, 1024,
        "ppo %d %d %d %d\n",
        player->fd,
        player->x,
        player->y,
        player->orientation);
        send_graphical(server, message);
    }
}
