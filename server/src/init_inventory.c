/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** init_inventory
*/

#include "server.h"

/**
 * @brief Initializes a player's inventory.
 *
 * This function initializes a player's inventory with default values.
 * Each type of resource is initialized to 0,
 * except for food which is initialized to 10.
 *
 * @param player The array of players.
 * @param fd The file descriptor of the player to initialize.
 */
void init_inventory(player_t *player, int fd)
{
    player[fd].inventory.food = 10;
    player[fd].inventory.linemate = 0;
    player[fd].inventory.deraumere = 0;
    player[fd].inventory.sibur = 0;
    player[fd].inventory.mendiane = 0;
    player[fd].inventory.phiras = 0;
    player[fd].inventory.thystame = 0;
}
