/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** init_map
*/

#include "server.h"

void init_map(server_t *server)
{
    server->map.tiles = malloc(sizeof(tile_t *) * server->opt->map_height);
    for (int i = 0; i < server->opt->map_height; i++) {
        server->map.tiles[i] = malloc(sizeof(tile_t) * server->opt->map_width);
        for (int j = 0; j < server->opt->map_width; j++) {
            server->map.tiles[i][j].food = 0;
            server->map.tiles[i][j].linemate = 0;
            server->map.tiles[i][j].deraumere = 0;
            server->map.tiles[i][j].sibur = 0;
            server->map.tiles[i][j].mendiane = 0;
            server->map.tiles[i][j].phiras = 0;
            server->map.tiles[i][j].thystame = 0;
            server->map.tiles[i][j].player = 0;
            server->map.tiles[i][j].egg = 0;
        }
    }
    server->map.width = server->opt->map_width;
    server->map.height = server->opt->map_height;
}
