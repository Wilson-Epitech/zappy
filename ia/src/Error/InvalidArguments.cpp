/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** InvalidArguments
*/

#include "Error.hpp"

/**
 * @brief This function override the "what" function in case their is an invalid argument
 *
 * @return char *
*/

const char *Ia::Error::InvalidArguments::what() const noexcept
{
    return "./zappy_ai -p port -n name1 -h 127.0.0.1";
}