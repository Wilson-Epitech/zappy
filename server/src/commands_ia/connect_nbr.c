/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** connect_nbr
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Nb Connected player to the team.
 *
 * This function return nb player connected.
 *
 * @param server The server instance.
 * @param player The array of players.
 * @param params The parameters sent with the command. This should be
 * the file descriptor of the player.
 *
*/
void command_connect_nbr(server_t *, player_t *, const char *)
{
    printf("connect_nbr\n");
}
