/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** server
*/


#include <netinet/ip.h>
#include <unistd.h>

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

#pragma once
typedef struct server_s {
    struct timeval timeout;
    struct sockaddr_in socket;
    char *buffer;
    int *client_socket;
    int port;
    size_t map_width;
    size_t map_height;
    char **names;
    size_t clients_number;
    size_t freq;
    int opt;
    int try_logged;
    int frst_socket;
    int socketlen;
    int nw_socket;
    int Anonymous_logged;
    int max_clients;
    int valread;
    int sd;
    int max_sd;
    fd_set readfds;
} server_t;

typedef struct cli_s {
    int anonymous_logged;
    int other_user;
    char *working_dir;
} cli_t;

//--------main.c -------------------------------//
int get_args(server_t *server, char *const *argv);

//--------server.c -------------------------//
int server_loop(server_t *server, cli_t *cli);

//--------init.c ----------------------//
void init_sock_struct(server_t *server);
int init_socket(int fd, int opt);
void init_data_struct(server_t *server);
void init_server(server_t *server);
char **init_array_reply(char **array);
char **init_array_commands(char **array);

//--------get_reply_code.c -------------//
char *get_reply_code(char *str);
void send_reply(int sd, char *reply_code);

//--------socket.c -----------------------//
void handle_client_socket(server_t *server);
void process_socket(server_t *server);
void reset_client_socket(server_t *server);
void add_to_socket_list(server_t *server);

void data_socket_loop(server_t *server);

//--------lib ----------------------------------------------//
char **my_word_array_delim(char const *str, char *separators);

//--------handle_input ---------------------------------------------------//
void handle_quit_command(server_t *server, char **array, int i);
void handle_user_command(server_t *server, cli_t *cli, char **array, int i);
void handle_pass_command(server_t *server, cli_t *cli, char **array, int i);
void handle_help_command(server_t *server, char **array);
void handle_noop_command(server_t *server, char **array);
void handle_cwd_cdup_command(server_t *server,
    cli_t *cli, char **array, int i);
void handle_list_command(server_t *server, cli_t *cli, char **array, int i);
