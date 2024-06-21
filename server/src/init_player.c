/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** init_player
*/

#include "server.h"
#include "string.h"
#include <time.h>

/**
 * @brief Init default value of the player
 * @param player
 * @param fd The client's fd
*/
void init_player(player_t *player, int fd)
{
    player[fd].team_id = -1;
    player[fd].level = 1;
    player[fd].x = 0;
    player[fd].y = 0;
    memset(player[fd].team_name, 0, 0);
    player[fd].orientation = 0;
    player[fd].fd = fd;
    player[fd].time = time(NULL);
    init_inventory(player, fd);
}
