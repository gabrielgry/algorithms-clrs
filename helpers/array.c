#include <stdio.h>
#include <stdlib.h>

#include "array.h"

void print_int_array(int array[], int length)
{
	printf("[");

	for (int index = 0; index < length; index++) {
		if (index == length - 1) {
			printf("%d", array[index]);
		} else {
			printf("%d, ", array[index]);
		}
	}

	printf("]\n");
}

void fill_array_with_shuffled_int(int array[], int length)
{
	for (int index = 0; index < length; index++) {
		array[index] = index;
	}

	for (int index = 0; index < length; index++) {
		int randomIndex = rand() % length;
		printf("\nrandomIndex: %d\n", randomIndex);

		int tmp = array[index];
		array[index] = array[randomIndex];
		array[randomIndex] = tmp;
	}	
}


