#include <stdio.h>
#include "menu.h"
#include "price.h"

/**
 * @brief Displays the coffee menu to the user.
 *
 * @param menu Array of Coffee structs containing coffee details
 * @param size Number of items in the menu array
 */
void show_menu(const Coffee menu[], int size) {
    printf("Welcome!\nChoose your coffee:\n");
    printf("ID | Coffee Name      -> Price\n");
    printf("-------------------------------\n");

    for (int i = 0; i < size; i++) {
        printf("%2d | %-16s -> ", menu[i].id, menu[i].name);
        print_price(menu[i].price_cents, menu[i].currency);
        printf("\n");
    }

    printf("-------------------------------\n");
}


/**
 * @brief Finds a coffee in the menu by its ID.
 *
 * @param menu Array of Coffee structs
 * @param size Number of items in the menu
 * @param id Coffee ID to search for
 * @return Pointer to the Coffee if found, otherwise NULL
 */
const Coffee *find_coffee_by_id(const Coffee menu[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (menu[i].id == id) {
            return &menu[i];
        }
    }
    return NULL;
}
