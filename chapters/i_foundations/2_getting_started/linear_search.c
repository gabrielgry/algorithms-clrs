#include <stdio.h>
#include "test.h"

unsigned int linear_search(int value, int array[], int size) {
	for(int i = 0; i < size; ++i) {
		if(array[i] == value) {
			return i;
		} 
	}
}

int main() {
	int array[] = {4, 3, 5, 2, 1};
	int size = 5;

	int index = linear_search(2, array, size);

	test_print_result(index == 3, "The index of the value is correct.");

	return 0;
}
