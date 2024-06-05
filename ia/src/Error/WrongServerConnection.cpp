/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** WrongServerConnection
*/

#include "Error.hpp"

/**
 * @brief This function override the "what" function in case the server connection fail
 *
 * @return char *
*/

const char *Ia::Error::WrongServerConnection::what() const noexcept
{
    return "Connection Failed";
}