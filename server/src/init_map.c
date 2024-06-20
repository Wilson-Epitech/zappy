/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** init_map
*/

#include "server.h"
#include <stdlib.h>

static void init_tiles(server_t *server, int i, int j)
{
    server->map.tiles[i][j].resources[FOOD] =
        &server->map.tiles[i][j].food;
    server->map.tiles[i][j].resources[LINEMATE] =
        &server->map.tiles[i][j].linemate;
    server->map.tiles[i][j].resources[DERAUMERE] =
        &server->map.tiles[i][j].deraumere;
    server->map.tiles[i][j].resources[SIBUR] =
        &server->map.tiles[i][j].sibur;
    server->map.tiles[i][j].resources[MENDIANE] =
        &server->map.tiles[i][j].mendiane;
    server->map.tiles[i][j].resources[PHIRAS] =
        &server->map.tiles[i][j].phiras;
    server->map.tiles[i][j].resources[THYSTAME] =
        &server->map.tiles[i][j].thystame;
    server->map.tiles[i][j].resources[PLAYER] =
        &server->map.tiles[i][j].player;
    server->map.tiles[i][j].resources[EGG] =
        &server->map.tiles[i][j].egg;
}

void init_map(server_t *server)
{
    server->map.tiles = malloc(sizeof(tile_t *) * (server->opt->map_height));
    for (size_t i = 0; i < server->opt->map_height; i++) {
        server->map.tiles[i] = malloc(sizeof(tile_t) * server->opt->map_width);
        for (size_t j = 0; j < server->opt->map_width; j++) {
            server->map.tiles[i][j].food = 0;
            server->map.tiles[i][j].linemate = 0;
            server->map.tiles[i][j].deraumere = 0;
            server->map.tiles[i][j].sibur = 0;
            server->map.tiles[i][j].mendiane = 0;
            server->map.tiles[i][j].phiras = 0;
            server->map.tiles[i][j].thystame = 0;
            server->map.tiles[i][j].player = 0;
            server->map.tiles[i][j].egg = 0;
            init_tiles(server, i, j);
        }
    }
    server->map.width = server->opt->map_width;
    server->map.height = server->opt->map_height;
}
