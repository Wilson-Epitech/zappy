/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** fork
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

/**
 * @brief Forks a new player.
 * This function creates a new player and adds it to the server's player list.
 * @param server The server instance.
 * Not used in this function but included for
 * consistency with other command handlers.
 * @param player The array of players.
 * @param params The parameters sent with the command.
 * This should be the file descriptor of the player.
*/
void command_fork(server_t *, player_t *, const char *)
{
    printf("Fork command\n");
}
