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
    int time;
} command_handler_t;

typedef struct command_server_s {
    char *name;
    void(*func)(server_t *, player_t *, char **);
} command_server_t;

/* Commands GUI */
void command_msz(server_t *server, player_t *player, const char *params);
void command_sgt(server_t *server, player_t *player, const char *params);
void command_sst(server_t *server, player_t *player, const char *params);
void command_tna(server_t *server, player_t *player, const char *);
void command_ppo(server_t *server, player_t *player, const char *params);
void command_plv(server_t *server, player_t *player, const char *params);
void command_pin(server_t *, player_t *player, const char *params);
void command_pex(server_t *server, player_t *player, const char *params);
void command_pbc(server_t *server, player_t *player, const char *params);
void command_bct_all(server_t *server, player_t *player, const char *params);
void command_bct(server_t *server, player_t *player, const char *params);
void command_seg(server_t *server, player_t *player, const char *params);

/* Commands Ia */
void command_broadcast(server_t *server, player_t *player, const char *params);
void command_connect_nbr(server_t *, player_t *, const char *);
void command_forward(server_t *server, player_t *player, const char *params);
void command_inventory(server_t *, player_t *player, const char *);
void command_left(server_t *, player_t *player, const char *);
void command_look(server_t *, player_t *, const char *);
void command_right(server_t *, player_t *player, const char *);
void command_take(server_t *server, player_t *player, const char *);
void command_set(server_t *server, player_t *player, const char *params);
void command_eject(server_t *server, player_t *player, const char *);
void command_fork(server_t *, player_t *, const char *);
void command_incantation(server_t *server,
    player_t *player, const char *params);

/* Commands Server*/
void command_give(server_t *, player_t *player, char **args);
void command_teleport(server_t *server, player_t *player, char **args);
void command_set_level(server_t *server, player_t *player, char **args);
void command_immortal(server_t *server, player_t *player, char **args);
void command_kill(server_t *server, player_t *player, char **args);

#endif /* !CMD_HANDLER_H_ */
