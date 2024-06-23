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

/**
 * @brief Executes the seg command and end the game
 * 
 * @param server
 * @param player
 * @param cmd
 */
void command_seg(server_t *server, player_t *, const char *)
{
    server->is_end = true;
}
