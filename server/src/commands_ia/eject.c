/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** eject
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

static void eject_forward(server_t *server, player_t *player)
{
    if (player->orientation == 0) {
        player->y = (player->y - 1 + server->opt->map_height)
            % server->opt->map_height;
    }
    if (player->orientation == 1) {
        player->y = (player->y + 1) % server->opt->map_height;
    }
    if (player->orientation == 2) {
        player->x = (player->x + 1) % server->opt->map_width;
    }
    if (player->orientation == 3) {
        player->x = (player->x - 1 + server->opt->map_width)
            % server->opt->map_width;
    }
    dprintf(player->fd, "ok\n");
}

/**
 * @brief Ejects the player in the direction they are facing.
 * This function ejects the player in the direction they are facing.
 * @param server The server instance.
 * Not used in this function but included for
 * consistency with other command handlers.
 * @param player The array of players.
 * @param params The parameters sent with the command.
 * This should be the file descriptor of the player.
*/
void command_eject(server_t *server, player_t *player, const char *)
{
    player_t other_player;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        other_player = server->players[i];
        if (other_player.x == player->x && other_player.y == player->y
            && player->is_elevating == false) {
            eject_forward(server, player);
        }
    }
}
