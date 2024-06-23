/*
** ZAPPY PROJECT, 2024
** YEP
** File description:
** inventaire
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

/**
 * @brief Structure to handle inventory
 * 
 * @param food Number of food
 * @param linemate Number of linemate
 * @param deraumere Number of deraumere
 * @param sibur Number of sibur
 * @param mendiane Number of mendiane
 * @param phiras Number of phiras
 * @param thystame Number of thystame
 * @param resources Array of resources
 * @return inventory_t
 */
typedef struct inventory_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int *resources[7];
} inventory_t;

#endif /* !INVENTORY_H_ */
