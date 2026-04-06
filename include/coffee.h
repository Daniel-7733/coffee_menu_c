#ifndef COFFEE_H
#define COFFEE_H

/**
 * @struct Coffee
 * @brief Represents a coffee item in the menu.
 *
 * Contains identifying and pricing information for a coffee.
 */
typedef struct {
    int id; 
    char name[20];
    int price_cents;
    char currency;
} Coffee;

#endif