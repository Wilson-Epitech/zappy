/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** kill
*/

#include "server.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Kills a player.
 * 
 * @param server The server instance.
 * @param fd The file descriptor of the player to kill.
*/
static void kill_player(server_t *server, int fd)
{
    if (server->players[fd].is_dead == true) {
        printf("Player is already dead\n");
        return;
    }
    if (is_player_connect(server, fd) == false) {
        printf("Player is not connected\n");
        return;
    }
    server->players[fd].is_dead = true;
    dprintf(fd, "dead\n");
    printf("Player %d is dead\n", fd);
    clear_client(server, fd);
}

/**
 * @brief Kills a player.
 * 
 * @param server The server instance.
 * @param server The server instance.
 * @param fd The file descriptor of the player to kill.
*/
void command_kill(server_t *server, player_t *player, char **args)
{
    int fd = 0;

    if (get_array_size(args) != 2) {
        dprintf(player->fd, "Wrong Arguments\n");
        return;
    }
    fd = atoi(args[1]);
    if (fd <= 0 || fd >= MAX_CLIENTS) {
        dprintf(player->fd, "Wrong Player\n");
        return;
    }
    if (server->players[fd].is_immortal == true) {
        dprintf(player->fd, "Player is immortal\n");
        return;
    }
    kill_player(server, fd);
}
