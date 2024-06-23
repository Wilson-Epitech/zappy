/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include "inventory.h"
    #include "tile.h"
    #include "command.h"

/**
 * @brief Structure to handle players
 * 
 * @param fd File descriptor
 * @param id Id of the player
 * @param team_id Id of the team
 * @param team_name Name of the team
 * @param x X position of the player
 * @param y Y position of the player
 * @param level Level of the player
 * @param orientation Orientation of the player
 * @param time Time of the player
 * @param is_elevating Is the player elevating
 * @param is_immortal Is the player immortal
 * @param is_dead Is the player dead
 * @param inventory Inventory of the player
 * @param cmd_queue Command queue of the player
 * @return player_t
 */
typedef struct player_s {
    int fd;
    int id;
    int team_id;
    char *team_name;
    int x;
    int y;
    int level;
    int orientation;
    time_t time;
    bool is_elevating;
    bool is_immortal;
    bool is_dead;
    inventory_t inventory;
    player_command_queue_t cmd_queue;
} player_t;

#endif /* !PLAYER_H_ */
