#include <stdio.h>

unsigned int LinearSearch(int value, int arr[], unsigned int n) {
	for(unsigned int i = 0; i < n; ++i) {
		if(arr[i] == value) {
			return i;
		} 
	}
}

void printArray(int a[], unsigned int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}

	printf("\n");
}

int main() {
	int a[] = {4, 3, 5, 2, 1, 8, 7, 6, 9, 0};
	unsigned int n = 10;

	printArray(a, n);

	unsigned int r = LinearSearch(9, a, n);

	printf("%d\n", r);

	return 0;
}
