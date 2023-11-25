#include <stdio.h>

int SumArray(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum = sum + a[i];
	}

	return sum;
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

	int r = SumArray(a, n);

	printf("%d\n", r);

	return 0;
}
