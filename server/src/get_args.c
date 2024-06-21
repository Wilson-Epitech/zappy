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

/**
 * @brief This function parse the basic options
 *
 * @param server
 * @param argv
 * @param i
 * @return int
*/
static int parse_basic_options(server_t *server, char *const *argv, int i)
{
    if (strcmp(argv[i], "-p") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->port = atoi(argv[i + 1]);
        server->opt->p = 1;
    }
    if (strcmp(argv[i], "-x") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->map_width = atoi(argv[i + 1]);
        server->opt->x = 1;
    }
    if (strcmp(argv[i], "-y") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->map_height = atoi(argv[i + 1]);
        server->opt->y = 1;
    }
    return SUCCESS;
}

/**
 * @brief This function get the teams names
 *
 * @param server
 * @param argv
 * @param i
 * @return int
*/
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
    server->opt->names[count] = NULL;
    return SUCCESS;
}

/**
 * @brief This function parse the advanced options
 *
 * @param server
 * @param argv
 * @param i
 * @return int
*/
static int parse_advanced_options(server_t *server, char *const *argv, int i)
{
    if (strcmp(argv[i], "-c") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->clients_number = atoi(argv[i + 1]);
        server->opt->c = 1;
    }
    if (strcmp(argv[i], "-f") == 0) {
        if (!is_number(argv[i + 1]))
            return FAILURE;
        server->opt->freq = atoi(argv[i + 1]);
        server->opt->f = 1;
    }
    if (strcmp(argv[i], "-n") == 0) {
        if (get_teams_names(server, argv, i) == FAILURE)
            return FAILURE;
        server->opt->n = 1;
    }
    return SUCCESS;
}

/**
 * @brief This function set the default team names
 *
 * @param server
 * @return int
*/
static int set_default_team_names(server_t *server)
{
    if (server->opt->n == 0) {
        server->opt->names = malloc(sizeof(char *) * 5);
        if (server->opt->names == NULL)
            return FAILURE;
        server->opt->names[0] = "Team1";
        server->opt->names[1] = "Team2";
        server->opt->names[2] = "Team3";
        server->opt->names[3] = "Team4";
        server->opt->names[4] = NULL;
        printf("\033[0;36m[TEAM NAMES]\033[0m not set"
            ", default are Team1, Team2, Team3, Team4\n");
    }
    return SUCCESS;
}

/**
 * @brief This function set the default values for the server
 *
 * @param server
 * @return int
*/
static int init_default_values(server_t *server)
{
    if (server->opt->p == 0) {
        server->opt->port = 4242;
        printf("\033[0;36m[PORT]\033[0m not set, default is 4242\n");
    }
    if (server->opt->x == 0 && server->opt->y == 0) {
        server->opt->map_width = 10;
        server->opt->map_height = 10;
        printf("\033[0;36m[MAP DIMENSIONS]\033[0m not set,default is 10x10\n");
    }
    if (set_default_team_names(server) == FAILURE)
        return FAILURE;
    if (server->opt->f == 0) {
        server->opt->freq = 100;
        printf("\033[0;36m[FREQUENCY]\033[0m not set, default is 100 tps\n");
    }
    if (server->opt->c == 0) {
        server->opt->clients_number = 4;
        printf("\033[0;36m[CLIENT NUMBER]\033[0m not set, default is 4\n");
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
    server->opt->p = 0;
    server->opt->x = 0;
    server->opt->y = 0;
    server->opt->n = 0;
    server->opt->c = 0;
    server->opt->f = 0;
    for (int i = 0; argv[i] != NULL; i += 1) {
        if (parse_basic_options(server, argv, i) == FAILURE)
            return FAILURE;
        if (parse_advanced_options(server, argv, i) == FAILURE)
            return FAILURE;
    }
    if (init_default_values(server) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
