#ifndef MENU_H
#define MENU_H

#include "coffee.h"

void show_menu(const Coffee menu[], int size);
const Coffee *find_coffee_by_id(const Coffee menu[], int size, int id);

#endif