#include <stdio.h>
#include <string.h>

void swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

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

void sortSelection(int* a, int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap(&(a[i]), &(a[min_idx]));
		}
	}
}

int main()
{
	int n = 0;
	int* a = readArray(&n);

	sortSelection(a, n);

	printArray(a, n);

	free(a);
	return 0;
}