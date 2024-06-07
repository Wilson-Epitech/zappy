/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** cmd_handler
*/

#ifndef CMD_HANDLER_H_
    #define CMD_HANDLER_H_
    #include "server.h"

typedef struct command_handler_s {
    char *name;
    void(*func)(server_t *, player_t *, const char *);
} command_handler_t;

void command_pnw(server_t *, player_t *, const char *);

#endif /* !CMD_HANDLER_H_ */
