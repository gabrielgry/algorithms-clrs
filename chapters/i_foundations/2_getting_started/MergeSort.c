#include <stdio.h>

void printArray(int arr[], size_t n) {
	for(unsigned int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void merge(int arr[], unsigned int start, unsigned int middle, unsigned int end) {
	
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

	unsigned int leftIndex = 0;
	unsigned int rightIndex = 0;
	unsigned int mainIndex = 0;

	while (leftIndex < leftLength && rightIndex < rightLength) {
		if (left[leftIndex] < right[rightIndex]) {
			arr[start + mainIndex] = left[leftIndex];
			leftIndex++;
		} else {
			arr[start + mainIndex] = right[rightIndex];
			rightIndex++;
		}

		mainIndex++;
	}

	for (leftIndex; leftIndex < leftLength; leftIndex++) {
		arr[start + mainIndex] = left[leftIndex];
		mainIndex++;
	} 

	for (rightIndex; rightIndex < rightLength; rightIndex++) {
		arr[start + mainIndex] = right[rightIndex];
		mainIndex++;
	}
}

void mergeSort(int arr[], unsigned int start, unsigned int end) {
	if (start >= end) {
		return;
	}

	unsigned int middle = (unsigned int) ((end - start) / 2) + start;

	mergeSort(arr, start, middle);
	mergeSort(arr, middle + 1, end);

	merge(arr, start, middle, end);
}

void main() {
	int arr[] = {5, 3, 7, 0, 9, 4, 8, 2, 1, 6};
	size_t n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr, n);
	
	mergeSort(arr, 0, (unsigned int) n - 1);
	
	printArray(arr, n);
}
