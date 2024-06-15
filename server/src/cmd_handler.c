/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** cmd_handler
*/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "cmd_handler.h"

/**
 * @brief Array of command with GUI.
 *
 * Each element is a struct with a command name
 * and a function pointer to the handler for that command.
 */
command_handler_t command_handlers[] = {
    {"pin", command_pin},
    {"msz", command_msz},
    {"sgt", command_sgt},
    {"sst", command_sst},
    {"tna", command_tna},
    {NULL, NULL}
};

/**
 * @brief Array of command with ia.
 *
 * Each element is a struct with a command name
 * and a function pointer to the handler for that command.
 */
command_handler_t command_handlers_ia[] = {
    {"Forward", command_pin},
    {"Right", command_msz},
    {"Left", command_sgt},
    {"Look", command_sst},
    {"Inventory", command_tna},
    {NULL, NULL}
};

/**
 * @brief Processes a command for the GUI.
 *
 * @param server The server instance.
 * @param player The player instance.
 * @param cmd The command to process.
 */
void process_command(server_t *server, player_t *player, char *cmd)
{
    char *params = {0};
    bool is_passed = false;

    printf("Processing command: `%s`\n", cmd);
    for (int i = 0; command_handlers[i].func != NULL; ++i) {
        if (strncmp(command_handlers[i].name, cmd,
        strlen(command_handlers[i].name)) == 0) {
            is_passed = true;
            params = cmd + strlen(command_handlers[i].name) + 1;
            printf("Params: `%s`\n", params);
            command_handlers[i].func(server, player, params);
            break;
        }
    }
    if (!is_passed) {
        printf("Wrong command\n");
        write(player->fd, "suc\n", strlen("suc\n"));
    }
}

/**
 * @brief Processes a command for IA.
 *
 * @param server The server instance.
 * @param player The player instance.
 * @param cmd The command to process.
 */
void process_command_ia(server_t *server, player_t *player, char *cmd)
{
    char *params = {0};
    bool is_passed = false;

    printf("Processing command: `%s`\n", cmd);
    for (int i = 0; command_handlers_ia[i].func != NULL; ++i) {
        if (strncmp(command_handlers_ia[i].name, cmd,
        strlen(command_handlers_ia[i].name)) == 0) {
            is_passed = true;
            params = cmd + strlen(command_handlers_ia[i].name) + 1;
            printf("Params: `%s`\n", params);
            command_handlers_ia[i].func(server, player, params);
            break;
        }
    }
    if (!is_passed) {
        printf("Wrong command\n");
        write(player->fd, "suc\n", strlen("suc\n"));
    }
}

