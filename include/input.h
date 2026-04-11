#ifndef INPUT_H
#define INPUT_H

#define NUMBER_INPUT_LIMIT 100
#define NAME_INPUT_LIMIT 300

int read_int_in_range(const char *prompt, int min, int max);
char *ask_user_coffee_name(const char *prompt);
void remove_newline(char *text);
void clear_buffer();

#endif