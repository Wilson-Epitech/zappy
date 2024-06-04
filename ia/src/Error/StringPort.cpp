/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** StringPort
*/

#include "Error.hpp"

/**
 * @brief This function override the "what" function in case the stoi of the port fail
 *
 * @return char *
*/

const char *Ia::Error::StringPort::what() const noexcept
{
    return "Stoi Failed. Maybe you have entered a wrong port?";
}