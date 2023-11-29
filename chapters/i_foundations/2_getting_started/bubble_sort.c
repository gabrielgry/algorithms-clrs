#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"
#include "test.h"

void bubble_sort(int array[], int size)
{
	if (size <= 1) {
		return;
	}

	for (int sorted_index = 0; sorted_index < size - 1; sorted_index++) {
		for (int comparison_index = size - 1; comparison_index > sorted_index; comparison_index--) {
			if (array[comparison_index] < array[comparison_index - 1]) {
				int smaller_value = array[comparison_index];
				array[comparison_index] = array[comparison_index - 1];
				array[comparison_index - 1] = smaller_value;
			}
		}
	}	
}

int main()
{
	int size = 10;
	int array[size];

	array_fill_with_shuffled(array, size);

	bubble_sort(array, size);

	bool is_ordered = array_check_asc_order(array, size);

	test_print_result(is_ordered, "The array is in ascendent order.");

	return 0;
}
