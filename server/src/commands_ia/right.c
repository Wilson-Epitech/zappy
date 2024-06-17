/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** right
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Turns the player 90 degrees to the right.
 * 
 * This function changes the player's direction to represent a 90 degree turn to the right.
 * 
 * @param server The server instance. Not used in this function but included for consistency with other command handlers.
 * @param player The array of players.
 * @param params The parameters sent with the command. This should be the file descriptor of the player.
*/
void command_right(server_t *server, player_t *player, const char *params)
{
    player->orientation = (player->orientation + 1) % 4;
    dprintf(player->fd, "ok\n");
}
