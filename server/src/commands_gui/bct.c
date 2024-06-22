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

static void display_tile(server_t *server, int x, int y, char *answer)
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

int digit_check(char *arg1, char *arg2)
{
    for (size_t i = 0; i < strlen(arg1); i++) {
        if (arg1[i] < '0' || arg1[i] > '9')
            return 1;
    }
    for (size_t i = 0; i < strlen(arg2); i++) {
        if (arg2[i] < '0' || arg2[i] > '9')
            return 1;
    }
    return 0;
}

int error_handling_bct(server_t *server, const char *params)
{
    char *tmp = strdup(params);
    char *arg1 = strtok(tmp, " ");
    char *arg2 = strtok(NULL, " ");
    int x = 0;
    int y = 0;

    if (arg1 == NULL || arg2 == NULL || strtok(NULL, " ") != NULL
    || digit_check(arg1, arg2) == 1) {
        free(tmp);
        return 1;
    }
    x = atoi(arg1);
    y = atoi(arg2);
    if (x < 0 || x >= (int) server->map.width || y < 0
    || y >= (int) server->map.height) {
        free(tmp);
        return 1;
    }
    free(tmp);
    return 0;
}

void command_bct(server_t *server, player_t *player, const char *params)
{
    char *answer;
    char *tmp;
    int x;
    int y;

    if (strcmp(params, "\0") == 0 || error_handling_bct(server, params) == 1) {
        dprintf(player->fd, "sbp\n");
        return;
    }
    answer = malloc(sizeof(char) * 222);
    tmp = strdup(params);
    x = atoi(strtok(tmp, " "));
    y = atoi(strtok(NULL, " "));
    display_tile(server, x, y, answer);
    send(player->fd, answer, strlen(answer), 0);
    free(answer);
}

void command_bct_all(server_t *server, player_t *player, const char *params)
{
    size_t max_size = server->map.height * server->map.width * 200;
    char *answer = malloc(sizeof(char) * max_size);
    char *tile_info = NULL;

    if (strcmp(params, "\0") != 0) {
        dprintf(player->fd, "sbp\n");
        return;
    }
    answer[0] = '\0';
    for (size_t i = 0; i < server->map.height; i++) {
        for (size_t j = 0; j < server->map.width; j++) {
            tile_info = malloc(sizeof(char) * 200);
            display_tile(server, j, i, tile_info);
            strcat(answer, tile_info);
            free(tile_info);
        }
    }
    send(player->fd, answer, strlen(answer), 0);
    printf("%s", answer);
    free(answer);
}
