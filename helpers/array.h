#include<stdbool.h>

#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

void array_print_int(int array[], int size);
void array_fill_with_shuffled(int array[], int size);
bool array_check_asc_order(int array[], int size);
bool array_check_desc_order(int array[], int size);

#endif
