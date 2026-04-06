#include <stdio.h>
#include <stdlib.h>

#include "app.h"
#include "coffee.h"
#include "menu.h"
#include "input.h"
#include "price.h"

/**
 * @brief Runs the main application workflow.
 *
 * Displays menu, handles user input, and calculates total bill.
 *
 * @return 0 on success, 1 on failure
 */
int run_app(void) {
    Coffee menu[] = {
        {1, "Cappuccino", 550, '$'},
        {2, "Caffe Latte", 475, '$'},
        {3, "Cortado", 425, '$'},
        {4, "Cold Brew", 500, '$'},
        {5, "Caffe Nero", 350, '$'},
        {6, "Caturra", 625, '$'},
        {7, "Caffe Mocha", 525, '$'},
        {8, "Cafe au Lait", 450, '$'},
        {9, "Catuai", 600, '$'},
        {10, "Cafe de Olla", 400, '$'}
    };

    int menu_size = (int)(sizeof(menu) / sizeof(menu[0]));
    int max_orders = 10;
    int total_cents = 0;

    show_menu(menu, menu_size);

    int total_orders = read_int_in_range(
        "How many coffees do you want to order? (1-10): ",
        1,
        max_orders
    );

    int *user_choices = malloc((size_t)total_orders * sizeof *user_choices);
    if (user_choices == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Choose your coffee numbers one by one:\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < total_orders; i++) {
        user_choices[i] = read_int_in_range("Enter your coffee number: ", 1, menu_size);
    }

    printf("-------------------------------------\n");

    for (int i = 0; i < total_orders; i++) {
        const Coffee *selected = find_coffee_by_id(menu, menu_size, user_choices[i]);
        if (selected != NULL) {
            printf("%d. You chose %s which costs ", i + 1, selected->name);
            print_price(selected->price_cents, selected->currency);
            printf("\n");
            total_cents += selected->price_cents;
        }
    }

    printf("-----------------------\n");
    printf("Total bill: ");
    print_price(total_cents, '$');
    printf("\n");
    printf("-----------------------\n");

    free(user_choices);
    return 0;
}
