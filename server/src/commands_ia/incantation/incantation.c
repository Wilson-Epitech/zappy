/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** incantation
*/

#include "server.h"
#include <string.h>
#include <stdio.h>

static void detect_level(server_t *server, player_t *player)
{
    if (player->level == 4) {
        level_four(server, player);
        return;
    }
    if (player->level == 5) {
        level_five(server, player);
        return;
    }
    if (player->level == 6) {
        level_six(server, player);
        return;
    }
    if (player->level == 7) {
        level_seven(server, player);
        return;
    }
}

/**
 * @brief Starts the incantation
 * @param server
 * @param player
*/
static void start_incantation(server_t *server, player_t *player)
{
    if (player->level == 1) {
        level_one(server, player);
        return;
    }
    if (player->level == 2) {
        level_two(server, player);
        return;
    }
    if (player->level == 3) {
        level_three(server, player);
        return;
    }
}

/**
 * @brief Executes the incantation command
 * @param server
 * @param player
 * @param command
*/
void command_incantation(server_t *server, player_t *player,
    const char *)
{
    if (player->is_elevating == false) {
        start_incantation(server, player);
    }
}
