#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "test.h"

int* add_binary_integers(int a[], int b[], int n)
{
	int *c = (int*)malloc((n + 1) * sizeof(int));

	int carry = 0;

	for(int i = 0; i < n; i++) {
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

int main()
{
	int size = 4;
	int a[] = {0, 0, 1, 1};
	int b[] = {0, 1, 1, 1};

	int *c = add_binary_integers(a, b, size);
	
	int expected_c[] = {0, 1, 0, 1, 1};

	bool are_equal = array_check_if_equal(c, expected_c, 5);

	test_print_result(are_equal, "The sum of the binary integers is correct.");

	return 0;
}
