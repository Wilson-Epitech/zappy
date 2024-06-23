/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** handle_tiles
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void init_tiles_quantity(tile_density_t *tile_density)
{
    tile_density->food = 0.5;
    tile_density->linemate = 0.3;
    tile_density->deraumere = 0.15;
    tile_density->sibur = 0.1;
    tile_density->mendiane = 0.1;
    tile_density->phiras = 0.08;
    tile_density->thystame = 0.05;
}

void ressources_switch(server_t *server,
    int i, int j, int resource_index)
{
    switch (resource_index) {
        case 2:
            server->map.tiles[i][j].deraumere += 1;
            break;
        case 3:
            server->map.tiles[i][j].sibur += 1;
            break;
        case 4:
            server->map.tiles[i][j].mendiane += 1;
            break;
        case 5:
            server->map.tiles[i][j].phiras += 1;
            break;
        case 6:
            server->map.tiles[i][j].thystame += 1;
            break;
        default:
            break;
    }
}

static void distribute_remaining_resources(server_t *server,
    int remaining, int resource_index)
{
    int i = 0;
    int j = 0;

    srand(time(NULL));
    while (remaining > 0) {
        i = rand() % server->opt->map_height;
        j = rand() % server->opt->map_width;
        switch (resource_index) {
        case 0:
            server->map.tiles[i][j].food += 1;
            break;
        case 1:
            server->map.tiles[i][j].linemate += 1;
            break;
        default:
            ressources_switch(server, i, j, resource_index);
            break;
        }
        remaining--;
    }
}

void refill_distribution(server_t *server)
{
    int total_tiles = server->opt->map_width * server->opt->map_height;
    int food_quantity = total_tiles * 0.5;
    int linemate_quantity = total_tiles * 0.3;
    int deraumere_quantity = total_tiles * 0.15;
    int sibur_quantity = total_tiles * 0.1;
    int mendiane_quantity = total_tiles * 0.1;
    int phiras_quantity = total_tiles * 0.08;
    int thystame_quantity = total_tiles * 0.05;

    distribute_remaining_resources(server, food_quantity % total_tiles, 0);
    distribute_remaining_resources(server, linemate_quantity % total_tiles, 1);
    distribute_remaining_resources(server,
        deraumere_quantity % total_tiles, 2);
    distribute_remaining_resources(server, sibur_quantity % total_tiles, 3);
    distribute_remaining_resources(server, mendiane_quantity % total_tiles, 4);
    distribute_remaining_resources(server, phiras_quantity % total_tiles, 5);
    distribute_remaining_resources(server, thystame_quantity % total_tiles, 6);
}

void refill_map(server_t *server)
{
    int total_t = server->opt->map_width * server->opt->map_height;
    int food_quantity = 0.5 * total_t;
    int linemate_quantity = 0.3 * total_t;
    int deraumere_quantity = 0.15 * total_t;
    int sibur_quantity = 0.1 * total_t;
    int mendiane_quantity = 0.1 * total_t;
    int phiras_quantity = 0.08 * total_t;

    for (size_t i = 0; i < server->opt->map_height; ++i) {
        for (size_t j = 0; j < server->opt->map_width; ++j) {
            server->map.tiles[i][j].food += food_quantity / total_t;
            server->map.tiles[i][j].linemate += linemate_quantity / total_t;
            server->map.tiles[i][j].deraumere += deraumere_quantity / total_t;
            server->map.tiles[i][j].sibur += sibur_quantity / total_t;
            server->map.tiles[i][j].mendiane += mendiane_quantity / total_t;
            server->map.tiles[i][j].phiras += phiras_quantity / total_t;
            server->map.tiles[i][j].thystame += (int)(0.5 * total_t) / total_t;
        }
    }
    refill_distribution(server);
}
