/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** cmd_handler
*/

#include "cmd_handler.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Array of command handlers.
 *
 * Each element is a struct with a command name
 * and a function pointer to the handler for that command.
 */
command_handler_t command_handlers[] = {
    {"pnw", command_pnw},
    {"tna", command_tna},
    {NULL, NULL}
};

/**
 * @brief Processes a command.
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
    if (!is_passed)
        printf("Wrong command\n");
}
