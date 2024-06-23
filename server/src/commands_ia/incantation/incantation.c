/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** incantation
*/

#include "server.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief Starts the incantation
 * @param server
 * @param player
*/
static void start_incantation(server_t *server, player_t *player)
{
    printf("Player %d\n", player->fd);
    if (player->level == 1)
        level_one(server, player);
    if (player->level == 2)
        level_two(server, player);
    if (player->level == 3)
        level_three(server, player);
    if (player->level == 4)
        level_four(server, player);
    if (player->level == 5)
        level_five(server, player);
    if (player->level == 6)
        level_six(server, player);
    if (player->level == 7)
        level_seven(server, player);
}

/**
 * @brief Executes the incantation command
 * @param server
 * @param player
 * @param command
*/
void command_incantation(server_t *server, player_t *player,
    const char *params)
{
    if (strcmp(params, "\0") != 0) {
        printf("Parameters are not correct\n");
        dprintf(player->fd, "ko\n");
        return;
    }
    if (player->is_elevating == false) {
        printf("Player %d is trying to start incantation\n", player->fd);
        start_incantation(server, player);
    }
}
