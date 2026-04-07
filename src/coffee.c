#include <stdlib.h>
#include <string.h>
#include "coffee.h"

char *copy_string(const char *source) {
    size_t len = strlen(source);
    char *copy = malloc(len + 1);

    if (copy == NULL) {
        return NULL;
    }

    strcpy(copy, source);
    return copy;
}

int init_coffee(Coffee *coffee, int id, const char *name, int price_cents, char currency) {
    if (coffee == NULL) {
        return 0;
    }

    coffee->name = copy_string(name);
    if (coffee->name == NULL) {
        return 0;
    }

    coffee->id = id;
    coffee->price_cents = price_cents;
    coffee->currency = currency;

    return 1;
}

void free_coffee(Coffee *coffee) {
    if (coffee == NULL) {
        return;
    }

    free(coffee->name);
    coffee->name = NULL;
}