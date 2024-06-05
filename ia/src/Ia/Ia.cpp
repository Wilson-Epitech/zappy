/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Ia
*/

#include "Bot.hpp"
#include "Error.hpp"

/**
 * @brief Function that allow to connect ia and server
 * @param ip
 * @param port
 * @param teamName
*/

void Ia::Bot::ServerConnection(const std::string &ip, int port, const std::string &teamName)
{
    struct sockaddr_in serv_addr;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw Ia::Error::WrongServerConnection();
        return;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
        throw Ia::Error::WrongServerConnection();
        return;
    }
    if (connect(sock, reinterpret_cast<struct sockaddr*>(&serv_addr), sizeof(serv_addr)) < 0) {
        throw Ia::Error::WrongServerConnection();
        return;
    }
}