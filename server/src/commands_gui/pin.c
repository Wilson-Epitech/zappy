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
 * @brief Check if the parameters are correct.
 *
 * @param server The server instance.
 * @param player The player instance.
 * @param player_nb The player number.
 * @return int SUCCESS or FAILURE.
 */
static int check_params(server_t *server, player_t *player, int player_nb)
{
    if (player_nb == player->fd)
        return FAILURE;
    if (player_nb > MAX_CLIENTS)
        return FAILURE;
    if (server->players[player_nb].fd == 0)
        return FAILURE;
    return SUCCESS;
}

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
void command_pin(server_t *server, player_t *player, const char *params)
{
    int fd = atoi(params);

    if (check_params(server, player, fd) == FAILURE) {
        dprintf(player->fd, "spb\n");
        return;
    }
    dprintf(player->fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
        fd,
        server->players[fd].x,
        server->players[fd].y,
        server->players[fd].inventory.food,
        server->players[fd].inventory.linemate,
        server->players[fd].inventory.deraumere,
        server->players[fd].inventory.sibur,
        server->players[fd].inventory.mendiane,
        server->players[fd].inventory.phiras,
        server->players[fd].inventory.thystame);
}
