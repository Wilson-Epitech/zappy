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

/**
 * @brief Array of command with GUI.
 *
 * Each element is a struct with a command name
 * and a function pointer to the handler for that command.
 */
command_handler_t command_handlers[] = {
    {"pbc", command_pin, 0},
    {"pin", command_pin, 0},
    {"msz", command_msz, 0},
    {"sgt", command_sgt, 0},
    {"sst", command_sst, 0},
    {"tna", command_tna, 0},
    {"bct", command_bct, 0},
    {"mct", command_bct_all, 0},
    {NULL, NULL, 0}
};

/**
 * @brief Array of command with ia.
 *
 * Each element is a struct with a command name
 * and a function pointer to the handler for that command.
 */
command_handler_t command_handlers_ia[] = {
    {"Forward", command_pin, 7},
    {"Right", command_msz, 7},
    {"Left", command_sgt, 7},
    {"Look", command_sst, 7},
    {"Inventory", command_tna, 1},
    {"Broadcast", command_broadcast, 7},
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
    bool is_passed = false;

    printf("Processing command: `%s`\n", cmd);
    for (int i = 0; command_handlers[i].func != NULL; ++i) {
        if (strncmp(command_handlers[i].name, cmd,
        strlen(command_handlers[i].name)) == 0) {
            is_passed = true;
            params = cmd + strlen(command_handlers[i].name) + 1;
            printf("Params: `%s`\n", params);
            command_handlers[i].func(server, player, params);
            break;
        }
    }
    if (!is_passed) {
        printf("Wrong command\n");
        write(player->fd, "suc\n", strlen("suc\n"));
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

void enqueue_command(player_command_queue_t *queue, const char *cmd,
    int execution_time)
{
    if (queue->count < 10) {
        queue->commands[queue->rear].cmd = strdup(cmd);
        queue->commands[queue->rear].execution_time =
            time(NULL) + execution_time;
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
    bool is_passed = false;

    printf("Processing command: `%s`\n", cmd);
    for (int i = 0; command_handlers_ia[i].func != NULL; ++i) {
        if (strncmp(command_handlers_ia[i].name, cmd,
        strlen(command_handlers_ia[i].name)) == 0) {
            is_passed = true;
            params = cmd + strlen(command_handlers_ia[i].name) + 1;
            printf("Params: `%s`\n", params);
            enqueue_command(queue, cmd, command_handlers_ia[i].time);
            break;
        }
    }
    if (!is_passed) {
        printf("Wrong command\n");
        write(player->fd, "suc\n", strlen("suc\n"));
    }
}
