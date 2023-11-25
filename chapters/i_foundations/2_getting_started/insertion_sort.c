#include <stdio.h>
#include "array.h"

void insertion_sort(int array[], int size)
{
	for (int unsorted_index = 1; unsorted_index < size; ++unsorted_index) {
		int unsorted_value = array[unsorted_index];
		
		int sorted_index = unsorted_index - 1;
        
		while (sorted_index >= 0 && array[sorted_index] > unsorted_value) {
			array[sorted_index + 1] = array[sorted_index];
			--sorted_index;
		}

		array[sorted_index + 1] = unsorted_value;
	}
}

int main()
{
	int size = 10;
	int array[size];

	array_fill_with_shuffled(array, size);

	array_print_int(array, size);

	insertion_sort(array, size);

	array_print_int(array, size);

	return 0;
}
