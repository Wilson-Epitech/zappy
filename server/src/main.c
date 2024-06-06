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


static int error_handling(server_t *server, int ac, char *const *av)
{
    if (ac < 12) {
        printf("bad option, run ./zappy_server -help\n");
        return FAILURE;
    }
    if (get_args(server, av) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

/**
 * @brief This is the main function for the server
 *
 * @return int
*/

int main(int argc, char *const *argv)
{
    server_t *server = malloc(sizeof(server_t));
    const char *usage = "USAGE: ./zappy_server -p port "
        "-x width -y height -n name1 name2 ... -c clientsNb -f freq\n";

    memset(server, 0, sizeof(server_t));
    server->opt = malloc(sizeof(options_t));
    if (argc == 2 && strcmp(argv[1], "-help") == SUCCESS) {
        printf("%s", usage);
        return SUCCESS;
    }
    if (error_handling(server, argc, argv) == FAILURE)
        return FAILURE;
    init_server(server, server->opt);
    run_server(server);
    cleanup_server(server);
    free(server->opt);
    free(server);
    return SUCCESS;
}
