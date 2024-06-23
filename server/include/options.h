/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** option
*/

#ifndef OPTIONS_H_
    #define OPTIONS_H_
    #include <stddef.h>

/**
 * @brief Structure to handle options
 *
 * @param port Port of the server
 * @param map_width Width of the map
 * @param map_height Height of the map
 * @param names Array of names
 * @param clients_number Number of clients
 * @param freq Frequency of the server
 * @param p Flag for port
 * @param x Flag for width
 * @param y Flag for height
 * @param n Flag for names
 * @param c Flag for clients
 * @param f Flag for frequency
 * @return options_t
 */
typedef struct options_s {
    int port;
    size_t map_width;
    size_t map_height;
    char **names;
    size_t clients_number;
    size_t freq;
    int p;
    int x;
    int y;
    int n;
    int c;
    int f;
} options_t;

#endif /* !OPTIONS_H_ */
