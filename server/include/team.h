/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** team
*/

#ifndef TEAM_H_
    #define TEAM_H_
    #include "egg.h"

/**
 * @brief Structure to handle teams
 * 
 * @param name Name of the team
 * @param player_count Number of players
 * @param egg_count Number of eggs
 * @param eggs Array of eggs
 * @return team_t
 */
typedef struct team_s {
    char *name;
    size_t player_count;
    int egg_count;
    egg_t *eggs;
} team_t;

#endif /* !TEAM_H_ */
