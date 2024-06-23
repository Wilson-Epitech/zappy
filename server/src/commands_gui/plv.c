/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** plv
*/

#include "server.h"
#include <stdio.h>
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
 * @brief Handles the 'plv' command from a client.
 *
 * This function is called when a client sends the 'plv' command.
 * It prints the player's level to the client.
 *
 * @param server The server instance.
 * @param player The array of players.
 * @param params The parameters sent with the command.
 */
void command_plv(server_t *server, player_t *player, const char *params)
{
    char **array = word_array_delim(params, " ");
    int size = get_array_size(array);
    int player_nb = 0;

    if (size != 1) {
        dprintf(player->fd, "spb\n");
        return;
    }
    player_nb = atoi(array[0]);
    if (check_params(server, player, player_nb) == FAILURE) {
        dprintf(player->fd, "spb\n");
        return;
    }
    dprintf(player->fd, "plv %d %d\n",
        server->players[player_nb].fd, server->players[player_nb].level);
}
