#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "input.h"
#include "coffee.h"


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
    char buffer[NUMBER_INPUT_LIMIT];

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


void remove_newline(char *text) {
    size_t len = strlen(text);

    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}

char *ask_user_coffee_name(const char *prompt) {
    char buffer[NAME_INPUT_LIMIT];

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Input error.\n");
        return NULL;
    }

    remove_newline(buffer);

    return copy_string(buffer);
}

