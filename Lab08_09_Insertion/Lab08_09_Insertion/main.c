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

void sortInsertion(int* a, int n)
{
	int i = 0;
#ifdef _DEBUG
	int n_swap = 0, n_comp = 0;
#endif
	for (i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
#ifdef _DEBUG
			n_comp++;
			n_swap++;
#endif
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
#ifdef _DEBUG
		n_comp++;
		n_swap++;
		printf("Iteration %d: ", i);
		printArray(a, n);
#endif
	}
#ifdef _DEBUG
	printf("n_swap = %d n_comp = %d\n", n_swap, n_comp);
#endif
}

int main()
{
	int n = 0;
	int* a = readArray(&n);

	sortInsertion(a, n);

	printArray(a, n);

	free(a);
	return 0;
}