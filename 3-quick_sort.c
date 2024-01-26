
#include "sort.h"

/**
 * partition - Arrays partition.
 * @array: Arrays to be sorted.
 * @first: First position.
 * @last: Last position.
 * @size: The array's size.
 * Return: int pivot's index.
 */
int partition(int *array, int first, int last, size_t size)
{
	int i = first - 1, aux, j;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			if (i < j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - Sorts a array of integers recursively.
 * @array: Array to be sorted.
 * @first: First position.
 * @last: Last position.
 * @size: The array's size.
 */
void qs(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		qs(array, first, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - Will sort a array of integers using the Quick.
 * Will sort algorithm in ascending order.
 * @array: The array to be sorted.
 * @size: Array's size.
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
