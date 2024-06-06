/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** commande
*/

#ifndef COMMANDE_H_
    #define COMMANDE_H_
    #include "server.h"

typedef struct command_s {
    char *cmd;
    int execution_time;
} command_t;

typedef struct player_command_queue_s {
    command_t commands[10];
    int front;
    int rear;
    int count;
} player_command_queue_t;

#endif /* !COMMANDE_H_ */
