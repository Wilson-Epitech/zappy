/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** commande
*/

#ifndef COMMANDE_H_
    #define COMMANDE_H_
    #include "server.h"

/**
 * @brief Structure to handle commands
 * 
 * @param cmd Name of the command
 * @param execution_time Time to wait before calling the function
 * @param id Id of the command
 * @param client_fd Client fd
 * @return command_t
 */
typedef struct command_s {
    char *cmd;
    int execution_time;
    int id;
    int client_fd;
} command_t;

/**
 * @brief Structure to handle commands
 * 
 * @param commands Array of commands
 * @param front Front of the queue
 * @param rear Rear of the queue
 * @param count Number of commands
 * @return player_command_queue_t
 */
typedef struct player_command_queue_s {
    command_t commands[10];
    int front;
    int rear;
    int count;
} player_command_queue_t;

#endif /* !COMMANDE_H_ */
