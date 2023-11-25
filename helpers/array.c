#include <stdio.h>

void print_int_array(int array[], size_t length) {
	printf("[");

	for (unsigned int index = 0; index < length; index++) {
		if (index == length - 1) {
			printf("%d", array[index]);
		} else {
			printf("%d, ", array[index]);
		}
	}

	printf("]\n");
}
