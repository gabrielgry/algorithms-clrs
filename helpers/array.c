#include <stdio.h>
#include <stdlib.h>

#include "array.h"

void print_int_array(int array[], int size)
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

void fill_array_with_shuffled_int(int array[], int size)
{
	for (int index = 0; index < size; index++) {
		array[index] = index;
	}

	for (int index = 0; index < size; index++) {
		int randomIndex = rand() % size;
		printf("\nrandomIndex: %d\n", randomIndex);

		int tmp = array[index];
		array[index] = array[randomIndex];
		array[randomIndex] = tmp;
	}	
}


