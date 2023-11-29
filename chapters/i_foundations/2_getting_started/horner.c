#include <stdio.h>
#include "test.h"

int horner(int coefficients[], int size, int x)
{
	int p = 0;	

	for (int i = size - 1; i >= 0; i--) {
		p = coefficients[i] + (x * p);
	}
	
	return p;
}

int main()
{
	int coefficients[3] = {1, 2, 3};
	int size = sizeof(coefficients)/sizeof(coefficients[0]);

	int result = horner(coefficients, size, 5);

	test_print_result(result == 86, "The solution of the polynomial function is correct.");
	
	return 0;
}
