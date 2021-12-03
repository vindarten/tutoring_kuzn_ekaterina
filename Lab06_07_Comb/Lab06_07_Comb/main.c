#include <stdio.h>
#include <string.h>

int* readArray(int* n)
{
	scanf_s("%d", n);
	int* b = malloc(*n * sizeof(int));
	int i;
	for (i = 0; i < *n; i += 1)
	{
		scanf_s("%d", &(b[i]));
	}
	return b;
}

void printArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; i += 1)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

void sortComb(int* a, int n)
{
	double k = 1.2473309;
	int i = 0, step = n - 1;

	while (step >= 1)
	{
		for (i = 0; i < n - step; i++)
		{
			if (a[i] > a[i + step])
			{
				swap(&(a[i]), &(a[i + step]));
			}
		}
		step /= k;
	}
}

int main()
{
	int n = 0;
	int* a = readArray(&n);

	sortComb(a, n);

	printArray(a, n);

	free(a);
	return 0;
}