#include <stdio.h>

int horner(int a[], size_t length, int x) {
	int p = 0;	

	for (int i = length - 1; i >= 0; i--) {
		p = a[i] + (x * p);
	}
	
	return p;
}

void print_array(int arr[], size_t n) {
	for (unsigned int i = 0; i < n; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");
}

int main() {
	int arr[2] = {1, 2};
	size_t n = sizeof(arr)/sizeof(arr[0]);

	print_array(arr, n);

	int result = horner(arr, n, 5);

	printf("%d\n", result);
	
	return 0;
}
