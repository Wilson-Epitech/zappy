/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** team
*/

#ifndef TEAM_H_
    #define TEAM_H_
    #include "egg.h"

typedef struct team_s {
    char *name;
    size_t player_count;
    int egg_count;
    egg_t *eggs;
} team_t;

#endif /* !TEAM_H_ */
