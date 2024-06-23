/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

/**
 * @brief Structure to handle eggs
 *
 * @param x X position of the egg
 * @param y Y position of the egg
 * @param id Id of the egg
 * @param hatching_time Time to wait before hatching
 * @return egg_t
 */
typedef struct egg_s {
    int x;
    int y;
    int id;
    int hatching_time;
} egg_t;

#endif /* !EGG_H_ */
