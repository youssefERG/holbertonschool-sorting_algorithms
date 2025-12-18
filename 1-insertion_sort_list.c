#include "sort.h"

/**
 * insertion_sort - sorts an array using Insertion sort
 * @array: array to sort
 * @size: size of the array
 */
void insertion_sort(int *array, size_t size)
{
	size_t i, j;
	int key;

	if (!array || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i;

		while (j > 0 && array[j - 1] > key)
		{
			array[j] = array[j - 1];
			j--;
			print_array(array, size);
		}
		array[j] = key;
	}
}
