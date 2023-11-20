#include <stdio.h>

int binary_search(int needle, int arr[], unsigned int start, unsigned int end) {

	if (end < start) {
		return -1;
	}

	unsigned int middle = (unsigned int)((end - start) / 2) + start;

	if (arr[middle] == needle) {
		return middle;
	}

	if (needle < arr[middle]) {
		binary_search(needle, arr, start, middle - 1);	
	} else {
		binary_search(needle, arr, middle + 1, end);
	}
}

void print_array(int arr[], unsigned int length) {
	for (unsigned int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}

int main() {
	unsigned int n = 10;
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	print_array(arr, n); 

	int needle = 4;

	int index = binary_search(needle, arr, 0, n - 1);

	printf("Needle: %d, ", needle); 
	
	if (index == -1) {
		printf("Not found");
	} else {
		printf("Index: %d",index); 
	}
	
	printf("\n");

	return 0;
}

