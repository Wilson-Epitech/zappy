/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** pin
*/

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Handles the 'pin' command from a client.
 *
 * This function is called when a client sends the 'pin' command.
 * It prints the player's
 * inventory to the client.
 * The inventory includes the player's position (x, y) and the
 * number of each resource the player has.
 *
 * @param server The server instance.
 * @param player The array of players.
 * @param params The parameters sent with the command.
 */
void command_pin(server_t *, player_t *player, const char *params)
{
    int size = strlen(params);
    int fd;

    if (size != 1 && size != 0)
        dprintf(atoi(params), "sbp\n");
    fd = atoi(params);
    dprintf(player[fd].fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
    player[fd].fd,
    player[fd].x, player[fd].y, player[fd].inventory.food,
    player[fd].inventory.linemate, player[fd].inventory.deraumere,
    player[fd].inventory.sibur, player[fd].inventory.mendiane,
    player[fd].inventory.phiras, player[fd].inventory.thystame);
}
