/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** left
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Turns the player 90 degrees to the left.
 * This function changes the player's direction
 * to represent a 90 degree turn to the left.
 * @param server The server instance.
 * Not used in this function but included for consistency
 * with other command handlers.
 * @param player The array of players.
 * @param params The parameters sent with the command.
 * This should be the file descriptor of the player.
*/
void command_left(server_t *server, player_t *player, const char *)
{
    player->orientation = (player->orientation + 3) % 4;
    dprintf(server->queue->commands[server->queue->front].client_fd, "ok\n");
}
