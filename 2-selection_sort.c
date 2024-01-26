#include "sort.h"

/**
 * swap_ints - Swaps the two integers in a array.
 * @a: First integer to be swapped.
 * @b: Second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Will sort an array of integers in an ascending order
 *                  using the selection sort of algorithm.
 * @array: A array of integers.
 * @size: The size of the array.
 *
 * Description: Print array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
