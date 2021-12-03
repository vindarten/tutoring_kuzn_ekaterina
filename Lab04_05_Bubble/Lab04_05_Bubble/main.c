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

void sortBubble(int* a, int n)
{
	int hasSwap = 1;
	int i = 0, j = 0;
	while (hasSwap)
	{
		hasSwap = 0;
		for (j = 0; j < n - 1 - i; j += 1)
		{
			if (a[j] > a[j + 1])
			{
				swap(&(a[j]), &(a[j + 1]));
				hasSwap = 1;
			}
		}
		i++;
	}
}

int main()
{
	int n = 0;
	int* a = readArray(&n);

	sortBubble(a, n);

	printArray(a, n);

	free(a);
	return 0;
}