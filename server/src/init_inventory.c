/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** init_inventory
*/

#include "server.h"

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
