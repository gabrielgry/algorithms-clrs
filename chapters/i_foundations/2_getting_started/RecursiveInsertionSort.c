#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void recursiveInsertionSort(int arr[], unsigned int n)
{
	if (n == 1)
	{
		return;
	}

	recursiveInsertionSort(arr, n - 1);

	int key = arr[n - 1];

	int j = n - 2;

	while (j >= 0 && arr[j] > key)
	{
		arr[j + 1] = arr[j];
		--j;
	}
	arr[j + 1] = key;
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

int main()
{
	int a[] = {4, 3, 5, 2, 1, 8, 7, 6, 9, 0};
	unsigned int n = 10;

	printArray(a, n);

	recursiveInsertionSort(a, n);

	printArray(a, n);

	return 0;
}
