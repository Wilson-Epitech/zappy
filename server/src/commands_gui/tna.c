/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** tna
*/
#include "server.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void command_tna(server_t *server, player_t *player, const char *)
{
    size_t len = 0;
    char *str = NULL;

    for (int i = 0; server->opt->names[i] != NULL; i += 1) {
        len = strlen(server->opt->names[i]);
        str = malloc(sizeof(char) * (len + 2));
        if (str == NULL)
            return;
        strcpy(str, server->opt->names[i]);
        str[len] = '\n';
        str[len + 1] = '\0';
        dprintf(player->fd, "tna %s", str);
        free(str);
    }
    return;
}
