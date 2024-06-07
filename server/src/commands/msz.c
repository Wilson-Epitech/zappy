/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** msz
*/

#include "server.h"
#include <stdio.h>

void command_msz(server_t *server, player_t *player, const char *params)
{
    (void)player;
    (void)params;
    printf("----------msz----------\nMap width: %ld\nMap height: %ld\n--------"
    "---------------\n", server->opt->map_width, server->opt->map_height);
}
