/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** cmd_handler
*/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "cmd_handler.h"
#include <unistd.h>

#include "cmd_handler.h"

/**
 * @brief Array of command with GUI.
 *
 * Each element is a struct with a command name
 * and a function pointer to the handler for that command.
*/
command_handler_t command_handlers[] = {
    {"pbc", command_pbc, 0},
    {"pin", command_pin, 0},
    {"msz", command_msz, 0},
    {"sgt", command_sgt, 0},
    {"sst", command_sst, 0},
    {"tna", command_tna, 0},
    {"bct", command_bct, 0},
    {"mct", command_bct_all, 0},
    {"plv", command_plv, 0},
    {"ppo", command_ppo, 0},
    {"pex", command_pex, 0},
    {"seg", command_seg, 0},
    {NULL, NULL, 0}
};

/**
 * @brief Array of command with ia.
 *
 * Each element is a struct with a command name
 * and a function pointer to the handler for that command.
*/
command_handler_t command_handlers_ia[] = {
    {"Forward", command_forward, 7},
    {"Right", command_right, 7},
    {"Left", command_left, 7},
    {"Look", command_look, 7},
    {"Inventory", command_inventory, 1},
    {"Broadcast", command_broadcast, 7},
    {"Connect_nbr", command_connect_nbr, 0},
    {"Take", command_take, 7},
    {"Set", command_set, 7},
    {"Eject", command_eject, 7},
    {"Fork", command_fork, 42},
    {NULL, NULL, 0}
};

/**
 * @brief Processes a command for the GUI.
 *
 * @param server The server instance.
 * @param player The player instance.
 * @param cmd The command to process.
*/
void process_command(server_t *server, player_t *player, char *cmd)
{
    char *params = {0};
    char **array = word_array_delim(cmd, " ");
    bool is_passed = false;

    if (array == NULL)
        return;
    printf("Processing command: `%s`\n", array[0]);
    for (int i = 0; command_handlers[i].func != NULL; ++i) {
        if (strcmp(command_handlers[i].name, array[0]) == 0) {
            is_passed = true;
            printf("Params: `%s`\n", params);
            command_handlers[i].func(server, player, params);
            break;
        }
    }
    if (!is_passed) {
        dprintf(player->fd, "suc\n");
    }
}

void handle_command_queue(player_command_queue_t *queue, server_t *server,
    player_t *player)
{
    time_t current_time = time(NULL);
    char *params = NULL;

    if (queue->count > 0 &&
        difftime(current_time, queue->commands[queue->front].execution_time)
        >= 0) {
        params = queue->commands[queue->front].cmd +
            strlen(command_handlers_ia[queue->commands->id].name) + 1;
        command_handlers_ia[queue->commands->id].func(server, player, params);
        queue->front = (queue->front + 1) % 10;
        queue->count--;
    }
}

static void enqueue_command(player_command_queue_t *queue, const char *cmd,
    int execution_time, int client_fd)
{
    if (queue->count < 10) {
        queue->commands[queue->rear].cmd = strdup(cmd);
        queue->commands[queue->rear].execution_time =
            time(NULL) + execution_time;
        queue->commands[queue->rear].client_fd = client_fd;
        queue->rear = (queue->rear + 1) % 10;
        queue->count++;
    }
}

/**
 * @brief Processes a command for IA.
 *
 * @param server The server instance.
 * @param player The player instance.
 * @param cmd The command to process.
*/
void process_command_ia(server_t *, player_t *player, char *cmd,
    player_command_queue_t *queue)
{
    char *params = {0};
    char **array = word_array_delim(cmd, " ");
    bool is_passed = false;

    printf("Processing command: `%s`\n", cmd);
    for (int i = 0; command_handlers_ia[i].func != NULL; ++i) {
        if (strcmp(command_handlers_ia[i].name, array[0]) == 0) {
            is_passed = true;
            params = cmd + strlen(command_handlers_ia[i].name) + 1;
            printf("Params: `%s`\n", params);
            queue->commands->id = i;
            enqueue_command(queue, cmd, (command_handlers_ia[i].time /
            server->opt->freq), player->fd);
            break;
        }
    }
    if (!is_passed) {
        dprintf(player->fd, "ko\n");
    }
}
