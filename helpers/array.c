#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

void array_print_int(int array[], int size)
{
	printf("[");

	for (int index = 0; index < size; index++) {
		if (index == size - 1) {
			printf("%d", array[index]);
		} else {
			printf("%d, ", array[index]);
		}
	}

	printf("]\n");
}

void array_fill_with_shuffled(int array[], int size)
{
	for (int index = 0; index < size; index++) {
		array[index] = index;
	}

	for (int index = 0; index < size; index++) {
		int randomIndex = rand() % size;

		int tmp = array[index];
		array[index] = array[randomIndex];
		array[randomIndex] = tmp;
	}	
}

bool array_check_asc_order(int array[], int size) {
	for (int index = 1; index < size; index++) {
		if (array[index - 1] > array[index]) {
			return false;
		}
	}

	return true;
}

bool array_check_desc_order(int array[], int size) {
	for (int index = 1; index < size; index++) {
		if (array[index - 1] < array[index]) {
			return false;
		}
	}

	return true;
}




