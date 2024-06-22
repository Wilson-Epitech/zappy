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
