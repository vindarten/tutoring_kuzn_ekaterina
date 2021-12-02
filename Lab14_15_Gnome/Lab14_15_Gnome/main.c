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

void sortGnome(int* a, int n)
{
	int i = 1, j = 2;
	while (i < n)
	{
		printf("i=%d j=%d a:", i, j);
		printArray(a, n);
		if (a[i - 1] <= a[i])
		{
			i = j;
			j++;
		}
		else
		{
			swap(&(a[i - 1]), &(a[i]));
			i--;
			if (i == 0)
			{
				i = j;
				j++;
			}
		}
	}
}

int main()
{
	int n = 0;
	int* a = readArray(&n);

	sortGnome(a, n);

	printArray(a, n);

	free(a);
	return 0;
}