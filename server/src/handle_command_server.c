/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** handle_command_server
*/

#include "server.h"
#include "cmd_handler.h"
#include <stdio.h>
#include <string.h>

command_server_t command_server[] = {
    {"give", command_give},
    {"teleport", command_teleport},
    {"set_level", command_set_level},
    {"immortal", command_immortal},
    {"kill", command_kill},
    {NULL, NULL},
};

void process_server_command(server_t *server, player_t *player, char *cmd)
{
    char **array = word_array_delim(cmd, " ");
    bool is_passed = false;

    if (array == NULL)
        return;
    for (int i = 0; command_server[i].func != NULL; ++i) {
        if (command_server[i].name && array[0] &&
            strcmp(command_server[i].name, array[0]) == 0) {
            is_passed = true;
            command_server[i].func(server, player, array);
            break;
        }
    }
    if (!is_passed) {
        dprintf(player->fd, "Wrong Command\n");
    }
}
