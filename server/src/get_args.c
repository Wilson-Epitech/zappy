/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** get_args
*/

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "server.h"

/**
 * @brief This funcrion take a stirg in parameters and check
 * if the string is a number or not
 * @param str
 * @return true
 * @return false
*/
static bool is_number(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

static int fill_args1(server_t *server, char *const *argv, int i)
{
    if (strcmp(argv[i], "-p") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->port = atoi(argv[i + 1]);
    }
    if (strcmp(argv[i], "-x") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->map_width = atoi(argv[i + 1]);
    }
    if (strcmp(argv[i], "-y") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->map_height = atoi(argv[i + 1]);
    }
    return SUCCESS;
}

static int get_teams_names(server_t *server, char *const *argv, int i)
{
    int count = 0;
    size_t size = 1;

    if (argv[i + 1][0] == '-')
        return FAILURE;
    i += 1;
    while (strcmp(argv[i], "-c") != 0) {
        server->opt->names =
            realloc(server->opt->names, sizeof(char *) * (size + 1));
        if (server->opt->names == NULL)
            return FAILURE;
        server->opt->names[count] = strdup(argv[i]);
        count += 1;
        size += 1;
        i += 1;
    }
    return SUCCESS;
}

static int fill_args2(server_t *server, char *const *argv, int i)
{
    if (strcmp(argv[i], "-c") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->clients_number = atoi(argv[i + 1]);
    }
    if (strcmp(argv[i], "-f") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->freq = atoi(argv[i + 1]);
    }
    if (strcmp(argv[i], "-n") == 0) {
        if (get_teams_names(server, argv, i) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

/**
 * @brief This function get the args passed as parameters
 * at the execution of `zappy_server`.
 *
 * @param server
 * @param argv
 * @return int
*/
int get_args(server_t *server, char *const *argv)
{
    server->opt->names = NULL;
    for (int i = 0; argv[i] != NULL; i += 1) {
        if (fill_args1(server, argv, i) == FAILURE)
            return FAILURE;
        if (fill_args2(server, argv, i) == FAILURE)
            return FAILURE;
    }
    server->opt->start_time = time(NULL);
    return SUCCESS;
}
