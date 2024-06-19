/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** inventory
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Displays the player's inventory.
 *
 * This function displays the player's inventory.
 *
 * @param server The server instance.
 * @param player The array of players.
 * @param params The parameters sent with the command. This should be
 * the file descriptor of the player.
 *
*/
void command_inventory(server_t *, player_t *player, const char *)
{
    printf("inventory\n");
    dprintf(player->fd, "[food %d, linemate %d, deraumere %d, sibur %d, "
    "mendiane %d, phiras %d, thystame %d]\n", player->inventory.food,
    player->inventory.linemate, player->inventory.deraumere,
    player->inventory.sibur, player->inventory.mendiane,
    player->inventory.phiras, player->inventory.thystame);
}
