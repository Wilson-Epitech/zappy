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
 * 
 * This function changes the player's direction to represent a 90 degree turn to the left.
 * 
 * @param server The server instance. Not used in this function but included for consistency with other command handlers.
 * @param player The array of players.
 * @param params The parameters sent with the command. This should be the file descriptor of the player.
*/
void command_forward(server_t *server, player_t *player, const char *params)
{
    if (params != NULL) {
        dprintf(player->fd, "ko\n");
        return;
    }
    switch (player->orientation) {
        case 0:
            player->y = (player->y - 1 + server->opt->map_height)
            % server->opt->map_height;
            break;
        case 1:
            player->y = (player->y + 1) % server->opt->map_height;
            break;
        case 2:
            player->x = (player->x + 1) % server->opt->map_width;
            break;
        case 3:
            player->x = (player->x - 1 + server->opt->map_width)
            % server->opt->map_width;
            break;
    }
    dprintf(player->fd, "ok\n");
}
