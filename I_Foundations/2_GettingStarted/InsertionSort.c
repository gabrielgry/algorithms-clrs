#include <stdio.h>

void insertionSort(int a[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = a[i];
		
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;
	}
}

void printArray(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}

	printf("\n");
}

int main() {
	int a[] = {4, 3, 5, 2, 1, 8, 7, 6, 9, 0};
	int n = 10;

	printArray(a, n);

	insertionSort(a, n);

	printArray(a, n);

	return 0;
}
