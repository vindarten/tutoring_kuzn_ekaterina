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

void printSubarray(int* a, int l, int r)
{
	int i;
	for (i = l; i <= r; i += 1)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sortQuick(int* a, int l, int r)
{
	if (l >= r)
	{
		return;
	}
	printf("Start subarray sort\n");
	printf("Subarray: ");
	printSubarray(a, l, r);
	int v = a[(l + r) / 2];
	printf("v = %d\n", v);
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < v)
		{
			i++;
		}
		while (v < a[j])
		{
			j--;
		}
		printf("i = %d j = %d\n", i, j);
		if (i >= j)
		{
			break;
		}
		swap(&(a[i]), &(a[j]));
		printSubarray(a, l, r);
		i++;
		j--;
	}
	printf("End subarray sort\n");
	sortQuick(a, l, j);
	sortQuick(a, j + 1, r);
}

int main()
{
	int n = 0;
	int* a = readArray(&n);

	sortQuick(a, 0, n-1);

	printArray(a, n);

	free(a);
	return 0;
}