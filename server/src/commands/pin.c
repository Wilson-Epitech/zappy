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

void command_pin(server_t *, player_t *player, const char *params)
{
    int size = strlen(params);
    int fd;

    if (size != 1 && size != 0)
        dprintf(atoi(params), "sbp\n");
    fd = atoi(params);
    dprintf(fd, "pin %d %d %d %d %d %d %d %d %d %d\n", player[fd].fd, 
    player[fd].x, player[fd].y, player[fd].inventory.food,
    player[fd].inventory.linemate, player[fd].inventory.deraumere,
    player[fd].inventory.sibur, player[fd].inventory.mendiane,
    player[fd].inventory.phiras, player[fd].inventory.thystame);
}
