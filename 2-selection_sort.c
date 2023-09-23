#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, n;
	int tmp;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = size - 1, n = i + 1; j > i; j--)
		{
			if (array[j] < array[n])
			{
				n = j;
			}
		}
		if (array[i] > array[n])
		{
			tmp = array[i];
			array[i] = array[n];
			array[n] = tmp;
			print_array(array, size);
		}
	}
}
