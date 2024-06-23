/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** give
*/

#include "server.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static void give_item(server_t *server, char *item, int quantity, int fd)
{
    tile_type_t object_type = get_object(item);

    if (object_type == ITEM_COUNT) {
        printf("Wrong item\n");
        return;
    }
    server->players[fd].inventory.resources[object_type][0] += quantity;
    printf("%d %s given\n", quantity, item);
}

/**
 * @brief Give an item to a player.
 *
 * @param server
 * @param player
 * @param args
*/
void command_give(server_t *server, player_t *player, char **args)
{
    int fd = 0;
    char *item = NULL;
    int quantity = 0;

    if (get_array_size(args) != 4) {
        dprintf(player->fd, "Wrong Arguments\n");
        return;
    }
    fd = atoi(args[1]);
    item = args[2];
    quantity = atoi(args[3]);
    if (fd <= 0 || quantity <= 0) {
        dprintf(player->fd, "Wrong fd or quantity\n");
        return;
    }
    if (is_player_connect(server, fd) == false) {
        dprintf(player->fd, "Player not found\n");
        return;
    }
    give_item(server, item, quantity, fd);
}
