/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** TeamAlreadyConnected
*/

#include "Error.hpp"

/**
 * @brief This function override the "what" function in case the user tries to connect with an existing team
 * 
 * @return char*
 */

const char *Ia::Error::TeamAlreadyConnected::what() const noexcept
{
    return "This team already exist.";
}