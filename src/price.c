#include <stdio.h>
#include "price.h"


/**
 * @brief Prints a formatted price.
 *
 * Example output: $5.50
 *
 * @param cents Price in cents
 * @param currency Currency symbol
 */
void print_price(int cents, char currency) {
    printf("%c%d.%02d", currency, cents / 100, cents % 100);
}

