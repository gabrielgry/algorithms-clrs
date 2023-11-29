#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#include "test.h"

void merge(int array[], int start, int middle, int end) {
	
	int leftLength = (middle + 1) - start;
	int rightLength = end - middle;
	
	int left[leftLength];
	int right[rightLength];

	for (int i = 0; i < leftLength; i++) {
		left[i] = array[start + i];
	}

	for (int i = 0; i < rightLength; i++) {
		right[i] = array[middle + 1 + i];
	}

	int leftIndex = 0;
	int rightIndex = 0;
	int mainIndex = 0;

	while (leftIndex < leftLength && rightIndex < rightLength) {
		if (left[leftIndex] < right[rightIndex]) {
			array[start + mainIndex] = left[leftIndex];
			leftIndex++;
		} else {
			array[start + mainIndex] = right[rightIndex];
			rightIndex++;
		}

		mainIndex++;
	}

	for (leftIndex; leftIndex < leftLength; leftIndex++) {
		array[start + mainIndex] = left[leftIndex];
		mainIndex++;
	} 

	for (rightIndex; rightIndex < rightLength; rightIndex++) {
		array[start + mainIndex] = right[rightIndex];
		mainIndex++;
	}
}

void merge_sort(int array[], int start, int end)
{
	if (start >= end) {
		return;
	}

	int middle = (int) ((end - start) / 2) + start;

	merge_sort(array, start, middle);
	merge_sort(array, middle + 1, end);

	merge(array, start, middle, end);
}

int main()
{
	int size = 10;
	int array[size];

	array_fill_with_shuffled(array, size);
	
	merge_sort(array, 0, size - 1);
	
	bool is_sorted = array_check_asc_order(array, size);

	test_print_result(is_sorted, "The array is in ascendent order");

	return 0;
}
