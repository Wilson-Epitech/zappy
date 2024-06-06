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

command_handler_t command_handlers[] = {
    {"test\n", example_command_handler},
    {NULL, NULL}
};

void example_command_handler(server_t *server,
    player_t *player, const char *params)
{
    printf("Example command executed with params: %s\n", params);
}

void process_command(server_t *server, player_t *player, const char *cmd)
{
    const char *params = {0};
    bool is_passed = false;

    printf("Processing command: `%s`\n", cmd);
    for (int i = 0; command_handlers[i].func != NULL; ++i) {
        if (strcmp(command_handlers[i].name, cmd) == 0) {
            is_passed = true;
            command_handlers[i].func(server, player, params);
            break;
        }
    }
    if (!is_passed)
        printf("Wrong command\n");
}
