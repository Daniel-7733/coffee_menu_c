#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



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



void show_menu(const Coffee menu[], int size);
int read_int_in_range(const char *prompt, int min, int max);
const Coffee *find_coffee_by_id(const Coffee menu[], int size, int id);
void print_price(int cents, char currency);
int run_app(void);




/**
 * @brief Entry point of the program.
 *
 * Calls the main application function.
 *
 * @return 0 on success, 1 on failure
 */
int main(void) {
    return run_app();
}



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
 * @brief Reads an integer input from the user within a given range.
 *
 * Validates input to ensure it is numeric and within bounds.
 *
 * @param prompt Message displayed to the user
 * @param min Minimum acceptable value
 * @param max Maximum acceptable value
 * @return A valid integer entered by the user
 */
int read_int_in_range(const char *prompt, int min, int max) {
    char buffer[100];

    while (true) {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        char *endptr;
        long value = strtol(buffer, &endptr, 10);

        if (endptr == buffer) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        while (*endptr == ' ' || *endptr == '\t') {
            endptr++;
        }

        if (*endptr != '\n' && *endptr != '\0') {
            printf("Invalid input. Please enter only a number.\n");
            continue;
        }

        if (value < min || value > max) {
            printf("Please enter a number between %d and %d.\n", min, max);
            continue;
        }

        return (int)value;
    }
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

