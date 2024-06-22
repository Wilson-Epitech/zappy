/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"


/**
 * @brief This function is used to get the arguments from the command line
 *
 * @param server
 * @param argv
 * @param argc
 * @return int
*/
static int error_handling(server_t *server, char *const *argv, int argc)
{
    const char *usage = "USAGE: ./zappy_server -p port "
        "-x width -y height -n name1 name2 ... -c clientsNb -f freq\n";

    if (get_args(server, argv) == FAILURE) {
        return FAILURE;
    }
    if (argc == 2 && strcmp(argv[1], "-help") == SUCCESS) {
        printf("%s", usage);
        return SUCCESS;
    }
    return SUCCESS;
}

/**
 * @brief This is the main function for the server
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *const *argv)
{
    server_t *server = malloc(sizeof(server_t));
    tile_density_t *tile_density = malloc(sizeof(tile_density_t));

    memset(server, 0, sizeof(server_t));
    server->opt = malloc(sizeof(options_t));
    if (error_handling(server, argv, argc) == FAILURE)
        return FAILURE;
    init_server(server, server->opt);
    init_queue(server);
    init_tiles_quantity(tile_density);
    run_server(server, tile_density);
    cleanup_server(server);
    free(server->opt);
    free(server);
    return SUCCESS;
}
