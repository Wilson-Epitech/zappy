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

// static void tiles_ressources(int i, int j, server_t *server,
//     int resource_index)
// {
//     switch (resource_index) {
//         case 0:
//             server->map.tiles[i][j].food += 1;
//             break;
//         case 1:
//             server->map.tiles[i][j].linemate += 1;
//             break;
//         case 2:
//             server->map.tiles[i][j].deraumere += 1;
//             break;
//         case 3:
//             server->map.tiles[i][j].sibur += 1;
//             break;
//         case 4:
//             server->map.tiles[i][j].mendiane += 1;
//             break;
//         case 5:
//             server->map.tiles[i][j].phiras += 1;
//             break;
//         case 6:
//             server->map.tiles[i][j].thystame += 1;
//             break;
//         default:
//             break;
//     }
// }

// static void distribute_remaining_resources(server_t *server,
//     int remaining, int resource_index)
// {
//     int i = 0;
//     int j = 0;

//     srand(time(NULL));
//     while (remaining > 0) {
//         i = rand() % server->opt->map_height;
//         j = rand() % server->opt->map_width;
//         tiles_ressources(i, j, server, resource_index);
//         remaining--;
//     }
// }

// static void distribute_resources(server_t *server,
//     tile_density_t *density, int total_tiles)
// {
//     distribute_remaining_resources(server, density->food % total_tiles, 0);
//     distribute_remaining_resources(server, density->linemate % total_tiles, 1);
//     distribute_remaining_resources(server,
//         density->deraumere % total_tiles, 2);
//     distribute_remaining_resources(server, density->sibur % total_tiles, 3);
//     distribute_remaining_resources(server, density->mendiane % total_tiles, 4);
//     distribute_remaining_resources(server, density->phiras % total_tiles, 5);
//     distribute_remaining_resources(server, density->thystame % total_tiles, 6);
// }

// void refill_map(server_t *server, time_t *start_time,
//     tile_density_t *density)
// {
//     time_t current_time = time(NULL);
//     time_t diff = current_time - *start_time;
//     int total_tiles = server->opt->map_width * server->opt->map_height;

//     if (diff < (long int)(20 / server->opt->freq))
//         return;
//     for (size_t i = 0; i < server->opt->map_height; i++) {
//         for (size_t j = 0; j < server->opt->map_width; j++) {
//             server->map.tiles[i][j].food = density->food / total_tiles;
//             server->map.tiles[i][j].linemate = density->linemate / total_tiles;
//             server->map.tiles[i][j].deraumere =
//                 density->deraumere / total_tiles;
//             server->map.tiles[i][j].sibur = density->sibur / total_tiles;
//             server->map.tiles[i][j].mendiane = density->mendiane / total_tiles;
//             server->map.tiles[i][j].phiras = density->phiras / total_tiles;
//             server->map.tiles[i][j].thystame = density->thystame / total_tiles;
//         }
//     }
//     distribute_resources(server, density, total_tiles);
//     *start_time = current_time;
// }
