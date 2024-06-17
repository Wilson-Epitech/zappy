/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** bct
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

void display_tile(server_t *server, int x, int y, char *answer)
{
    sprintf(answer, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
        server->map.tiles[y][x].food,
        server->map.tiles[y][x].linemate,
        server->map.tiles[y][x].deraumere,
        server->map.tiles[y][x].sibur,
        server->map.tiles[y][x].mendiane,
        server->map.tiles[y][x].phiras,
        server->map.tiles[y][x].thystame);
}

void command_bct(server_t *server, player_t *player, const char *params)
{
    char *answer = malloc(sizeof(char) * 222);
    char *tmp = strdup(params);
    int x = atoi(strtok(tmp, " "));
    int y = atoi(strtok(tmp, " "));

    (void)player;
    display_tile(server, x, y, answer);
    send(player->fd, answer, strlen(answer), 0);
    free(answer);
}

void command_bct_all(server_t *server, player_t *player, const char *params)
{
    char *answer = malloc(sizeof(char) * 222);

    (void)params;
    for (int i = 0; i < server->map.height; i++) {
        for (int j = 0; j < server->map.width; j++) {
            display_tile(server, j, i, answer);
            send(player->fd, answer, strlen(answer), 0);
            free(answer);
            answer = malloc(sizeof(char) * 222);
        }
    }
    free(answer);
}
