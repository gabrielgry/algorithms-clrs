#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], size_t length) {
	if (length <= 1) {
		return;
	}

	for (unsigned int i = 0; i < length - 1; i++) {
		for (unsigned int j = length - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}	
}

void fill_array(int arr[], size_t length) {
	for (unsigned int i = 0; i < length; i++) {
		arr[i] = (length - 1) - i;
	}
}

void print_array(int arr[], size_t length) {
	for (unsigned int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	size_t length = 10;

	int *arr = malloc(sizeof(int) * length);

	if (arr == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	fill_array(arr, length);
	print_array(arr, length);

	bubble_sort(arr, length);

	print_array(arr, length);

	free(arr);

	return 0;
}
