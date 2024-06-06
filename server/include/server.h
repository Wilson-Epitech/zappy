/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** server
*/


#include <netinet/ip.h>
#include <unistd.h>

/** @brief This return value
 * representing the `success`
 * of the program or function
*/
static const int SUCCESS = 0;

/** @brief This return value
 * representing the `failure`
 * of the program or function
*/
static const int FAILURE = 84;

#pragma once
typedef struct server_s {
    int port;
    size_t map_width;
    size_t map_height;
    char **names;
    size_t clients_number;
    size_t freq;
} server_t;

//--------main.c -------------------------------//
int get_args(server_t *server, char *const *argv);
