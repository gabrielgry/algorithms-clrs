#include <stdio.h>
#include <limits.h>

void print_array(int arr[], size_t n) {
	for(unsigned int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int merge_inversions(int arr[], unsigned int start, unsigned int middle, unsigned int end) {
	
	unsigned int leftLength = (middle + 1) - start;
	unsigned int rightLength = end - middle;
	
	int left[leftLength];
	int right[rightLength];

	for (unsigned int i = 0; i < leftLength; i++) {
		left[i] = arr[start + i];
	}

	for (unsigned int i = 0; i < rightLength; i++) {
		right[i] = arr[middle + 1 + i];
	}
	
	left[leftLength] = INT_MAX;
	right[rightLength] = INT_MAX;
	
	unsigned int inversions = 0;
	unsigned int leftIndex = 0;
	unsigned int rightIndex = 0;

	for (unsigned int mainIndex = start; mainIndex <= end; mainIndex++) {
		if (left[leftIndex] <= right[rightIndex]) {
			arr[mainIndex] = left[leftIndex];
			leftIndex++;
		} else {
			inversions = inversions + leftLength - leftIndex;	
			arr[mainIndex] = right[rightIndex];
			rightIndex++;
		}
	}

	return inversions;
}

int inversions_count(int arr[], unsigned int start, unsigned int end) {
	if (start >= end) {
		return 0;
	}

	unsigned int middle = (unsigned int) ((end - start) / 2) + start;

	int leftCount = inversions_count(arr, start, middle);
	int rightCount = inversions_count(arr, middle + 1, end);

	int count = merge_inversions(arr, start, middle, end);

	return count + leftCount + rightCount;
}

void main() {
	int arr[] = {2, 3, 8, 6, 1};
	size_t n = sizeof(arr)/sizeof(arr[0]);

	print_array(arr, n);
	
	int count = inversions_count(arr, 0, n - 1);

	print_array(arr, n);
	
	printf("%d\n", count);
}
