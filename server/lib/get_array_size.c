/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** get_array_size
*/

#include <stdlib.h>

/**
 * @brief Get the array size object
 *
 * @param array
 * @return int
 */
int get_array_size(char **array)
{
    size_t i = 0;

    while (array[i] != NULL) {
        i += 1;
    }
    return i;
}
