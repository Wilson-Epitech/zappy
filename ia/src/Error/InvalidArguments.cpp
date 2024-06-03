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
    return "Invalid Args";
}