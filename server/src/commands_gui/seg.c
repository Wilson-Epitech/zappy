/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** seg
*/

#include "server.h"
#include "player.h"
#include "inventory.h"
#include <stdbool.h>


void command_seg(server_t *server, player_t *, const char *)
{
     server->is_end = true;
}
