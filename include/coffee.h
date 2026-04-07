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
    char *name;
    int price_cents;
    char currency;
} Coffee;

int init_coffee(Coffee *coffee, int id, const char *name, int price_cents, char currency);
void free_coffee(Coffee *coffee);
char *copy_string(const char *source);

#endif