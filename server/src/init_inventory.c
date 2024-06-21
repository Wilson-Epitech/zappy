/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** init_inventory
*/

#include "server.h"

/**
 * @brief Initializes the resources of a player's inventory.
 *
 * This function initializes the resources of a player's inventory.
 * Each resource is initialized to the address of the corresponding
 * resource in the player's inventory.
 *
 * @param player The array of players.
 * @param fd The file descriptor of the player to initialize.
 */
static void init_inventory_ressources(player_t *player, int fd)
{
    player[fd].inventory.resources[FOOD] = &player[fd].inventory.food;
    player[fd].inventory.resources[LINEMATE] = &player[fd].inventory.linemate;
    player[fd].inventory.resources[DERAUMERE] =
        &player[fd].inventory.deraumere;
    player[fd].inventory.resources[SIBUR] = &player[fd].inventory.sibur;
    player[fd].inventory.resources[MENDIANE] = &player[fd].inventory.mendiane;
    player[fd].inventory.resources[PHIRAS] = &player[fd].inventory.phiras;
    player[fd].inventory.resources[THYSTAME] = &player[fd].inventory.thystame;
}

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
    init_inventory_ressources(player, fd);
}
