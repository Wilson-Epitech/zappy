/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** option
*/

#ifndef OPTIONS_H_
    #define OPTIONS_H_
    #include <stddef.h>

typedef struct options_s {
    int port;
    size_t map_width;
    size_t map_height;
    char **names;
    size_t clients_number;
    size_t freq;
    int start_time;
    int p;
    int x;
    int y;
    int n;
    int c;
    int f;
} options_t;

#endif /* !OPTIONS_H_ */
