#include <stdio.h>
#include <stdlib.h>

int* AddBinaryIntegers(int a[], int b[], unsigned int n) {
	int *c = (int*)malloc((n + 1) * sizeof(int));

	int carry = 0;
	for(unsigned int i = 0; i < n; i++) {
		int sum = (a[i] + b[i] + carry);
		
		if(sum == 0 || sum == 1) {
			c[i] = sum;
			carry = 0;
		} else if (sum == 2) {
			c[i] = 0;
			carry = 1;
		} else if (sum == 3) {
			c[i] = 1;
			carry = 1;
		}
	}
	c[n] = carry;

	return c;
}

void PrintArray(int arr[], unsigned int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void main() {
	int a[] = {0, 0, 1, 0, 0};
	int b[] = {1, 1, 1, 0, 0};
	unsigned int n = 5;

	int *c = AddBinaryIntegers(a, b, n);

	PrintArray(a, n);
	PrintArray(b, n);
	PrintArray(c, n + 1);
}
