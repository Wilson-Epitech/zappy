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
static void clear_client(server_t *server, int client_fd)
{
    close(client_fd);
    FD_CLR(client_fd, &server->read_fd);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == client_fd) {
            server->players[i].fd = 0;
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
 * @param bytes_read The number of bytes read from the client.
 * @param buffer The buffer containing the data read from the client.
 */
static void read_client_data(server_t *server,
    int client_fd, ssize_t, char *buffer)
{
    printf("Received from %d: %s\n", client_fd, buffer);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->players[i].fd == client_fd) {
            process_command(server, &server->players[i], buffer);
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
        buffer[bytes_read - 2] = '\0';
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
