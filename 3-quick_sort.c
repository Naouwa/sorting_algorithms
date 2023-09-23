#include "sort.h"

void swap(int *array, size_t size, int *m, int *n);
size_t partition(int *array, size_t size, ssize_t left, ssize_t right);
void quicksort(int *array, size_t size, ssize_t left, ssize_t right);
void quick_sort(int *array, size_t size);


/**
 * swap - it swaps two indexes values
 * @array: the array to be swaped
 * @size: the size of the array
 * @m: place holder
 * @n: place holder
 * Return: void
 */
void swap(int *array, size_t size, int *m, int *n)
{
	if (*m != *n)
	{
		*m = *m + *n;
		*n = *m - *n;
		*m = *m - *n;
		print_array((const int *)array, size);
	}
}

/**
 * partition - partitions the array
 * @array: the array to be sort
 * @size: the size of the array
 * @left: the lowest index
 * @right: the highest index
 *
 * Return: void
 */
size_t partition(int *array, size_t size, ssize_t left, ssize_t right)
{
	int i, j, sheft = array[right];

	for (i = j = left; j < right; j++)
		if (array[j] < sheft)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[right]);

	return (i);
}

/**
 * quicksort - quicksorts via partitioning
 * @array: the array to be sorted
 * @size: the size of the array
 * @left: the lower index
 * @right: the highest index
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t left, ssize_t right)
{
	if (left < right)
	{
		size_t part = partition(array, size, left, right);

		quicksort(array, size, left, part - 1);
		quicksort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - calls quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
