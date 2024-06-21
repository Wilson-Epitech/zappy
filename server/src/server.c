/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** server
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cmd_handler.h"
#include <arpa/inet.h>

/**
 * @brief Clears a client from the server.
 *
 * Closes the client's file descriptor, removes it from the server's
 * read file descriptor set, and clears it from the server's players array.
 *
 * @param server The server instance.
 * @param client_fd The file descriptor of the client to clear.
 */
void clear_client(server_t *server, int client_fd)
{
    close(client_fd);
    FD_CLR(client_fd, &server->read_fd);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == client_fd) {
            memset(&server->players[i], 0, sizeof(player_t));
            break;
        }
    }
}

/**
 * @brief Reads data from a client and processes it.
 *
 * Prints the received data, finds the player associated with the client,
 * and processes the received data as a command from that player.
 *
 * @param server The server instance.
 * @param client_fd The file descriptor of the client.
 * @param buffer The buffer containing the data read from the client.
 */
static void read_client_data(server_t *server,
    int client_fd, ssize_t, char *buffer)
{
    printf("Received from %d: `%s`\n", client_fd, buffer);
    if (server->players[client_fd].team_id == -2) {
        printf("%d\n", server->players[client_fd].id);
        process_command(server, &server->players[client_fd], buffer);
        return;
    } else if (server->players[client_fd].team_id > -1) {
        process_command_ia(server, &server->players[client_fd], buffer,
            server->queue);
    }
}

/**
 * @brief Check player team and store it if correct
 * @param server
 * @param client_fd
 * @param buffer Client input
*/
static void handle_team(server_t *server, int client_fd, char *buffer)
{
    if (strcmp("GRAPHIC", buffer) == 0) {
        printf("GRAPHIC\n");
        server->players[client_fd].team_id = -2;
    }
    for (int i = 0; i < get_array_size(server->opt->names); ++i) {
        if (strcmp(server->opt->names[i], buffer) == 0) {
            server->players[client_fd].team_id = i;
            server->players[client_fd].team_name =
                malloc(sizeof(char) * (strlen(server->opt->names[i]) + 1));
            strcpy(server->players[client_fd].team_name,
                server->opt->names[i]);
            dprintf(client_fd, "%ld\n", server->opt->clients_number);
            dprintf(client_fd, "%ld %ld\n",
                server->opt->map_height, server->opt->map_width);
            command_pnw(server, client_fd);
            break;
        }
    }
}

/**
 * @brief Handles a client.
 *
 * Reads data from the client. If an error occurs or the client disconnects,
 * clears the client from the server. Otherwise, processes the received data.
 *
 * @param server The server instance.
 * @param client_fd The file descriptor of the client.
 */
void handle_client(server_t *server, int client_fd)
{
    char buffer[1024] = {0};
    ssize_t bytes_read = 0;

    bytes_read = read(client_fd, buffer, sizeof(buffer));
    if (bytes_read <= 0) {
        if (bytes_read == 0)
            printf("Client disconnected: %d\n", client_fd);
        else
            perror("read");
        clear_client(server, client_fd);
    } else {
        buffer[bytes_read - 1] = '\0';
        if (server->players[client_fd].team_id == -1) {
            handle_team(server, client_fd, buffer);
            return;
        }
        read_client_data(server, client_fd, bytes_read, buffer);
    }
}

/**
 * @brief Cleans up the server.
 *
 * Closes the server's file descriptor and the file descriptors
 * of all connected clients, and prints a message indicating that
 * the server has been cleaned up.
 *
 * @param server The server instance.
 */
void cleanup_server(server_t *server)
{
    close(server->fd);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd != 0) {
            close(server->players[i].fd);
        }
    }
    printf("Server cleaned up.\n");
}
