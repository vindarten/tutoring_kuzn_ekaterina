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

void sortShell(int* a, int n)
{
	int i = 0;
	int step = 0;
#ifdef _DEBUG
	int n_swap = 0, n_comp = 0, n_iter = 0;
#endif
	for (step = n / 2; step > 0; step /= 2)
	{
		for (i = step; i < n; i++)
		{
			int temp = a[i];
			int j = i - step;
			while (j >= 0 && a[j] > temp)
			{
#ifdef _DEBUG
				n_comp++;
				n_swap++;
#endif
				a[j + step] = a[j];
				j -= step;
			}
			a[j + step] = temp;
#ifdef _DEBUG
			n_comp++;
			n_swap++;
			n_iter++;
			printf("n_iter = %d step = %d: ", n_iter, step);
			printArray(a, n);
#endif
		}
	}
#ifdef _DEBUG
	printf("n_swap = %d n_comp = %d\n", n_swap, n_comp);
#endif
}

int main()
{
	int n = 0;
	int* a = readArray(&n);

	sortShell(a, n);

	printArray(a, n);

	free(a);
	return 0;
}