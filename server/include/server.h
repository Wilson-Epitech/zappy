/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #include <sys/select.h>
    #include <netinet/in.h>
    #include "player.h"
    #include "team.h"
    #include "map.h"
    #include "options.h"

/** @brief This return value
 * representing the `success`
 * of the program or function
*/
static const int SUCCESS = 0;

/** @brief This return value
 * representing the `failure`
 * of the program or function
*/
static const int FAILURE = 84;

    #define MAX_CLIENTS 100
    #define MAX_TEAMS 10

typedef struct server_s {
    int port;
    int fd;
    struct sockaddr_in addr;
    fd_set read_fd;
    fd_set write_fd;
    player_t players[MAX_CLIENTS];
    team_t teams[MAX_TEAMS];
    map_t map;
    options_t *opt;
} server_t;

//--------main.c -------------------------------//
int get_args(server_t *server, char *const *argv);

//--------server.c -------------------------------//
void init_server(server_t *server, options_t *opt);
void run_server(server_t *server);
void accept_client(server_t *server);
void handle_client(server_t *server, int client_fd);
void process_command(server_t *server, player_t *player, char *cmd);
void cleanup_server(server_t *server);

#endif /* !SERVER_H_ */
