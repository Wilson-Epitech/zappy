/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** free_slots
*/

#include "server.h"
#include <string.h>

/**
 * @brief return the number of slots available in a team
 *
 * @param server
 * @param player
 * @return int
*/
int free_slots(server_t *server, player_t *player)
{
    int index = 0;
    int slots = 0;

    for (int i = 0; i < server->players_connected; ++i) {
        if (strcmp(server->teams[i].name, player->team_name) == 0) {
            index = i;
            break;
        }
    }
    slots = server->opt->clients_number - server->teams[index].player_count;
    return slots;
}
