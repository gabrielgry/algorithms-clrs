#include <stdio.h>
#include "array.h"

void insertion_sort(int array[], int length)
{
	for (int unsorted_index = 1; unsorted_index < length; ++unsorted_index) {
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
	int length = 10;
	int array[length];

	fill_array_with_shuffled_int(array, length);

	print_int_array(array, length);

	insertion_sort(array, length);

	print_int_array(array, length);

	return 0;
}
