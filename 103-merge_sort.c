#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_left_right - Prints the left and the right partitions.
 * @array: Array.
 * @size: Size of the second array.
 * @first: Starting position.
 * @mid: Middle position.
 */
void print_left_right(int *array, int size, int first, int mid)
{
	int k;

	printf("Merging...\n");
	printf("[left]: ");
	k = first;
	while (k < mid)
	{
		if (k != mid - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}

	printf("[right]: ");
	k = mid;
	while (k < size)
	{
		if (k < size - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}
}

/**
 * merge - Will merge the values in the position of the array.
 * @array: First array.
 * @size: Size of the second array.
 * @cpy: Copy of array.
 * @first: Initial position.
 * @mid: Middle position.
 * first one of the 2nd array.
 */
void merge(int *array, int size, int first, int mid, int *cpy)
{
	int i, j, k;

	print_left_right(array, size, first, mid);

	i = first;
	j = mid;

	printf("[Done]: ");
	k = first;
	while (k < size)
	{
		if (i < mid && (j >= size || array[i] <= array[j]))
		{
			cpy[k] = array[i];
			i++;
		}
		else
		{
			cpy[k] = array[j];
			j++;
		}
		if (k < size - 1)
			printf("%d, ", cpy[k]);
		else
			printf("%d\n", cpy[k]);
		k++;
	}
}
/**
 * mergeSort - Array separator.
 * @cpy: Copy of the array.
 * @first: Starting position.
 * @size: The size of the original array.
 * @array: The original array.
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int mid;

	if (size - first < 2)
		return;

	mid = (size + first) / 2;

	mergeSort(array, first, mid, cpy);
	mergeSort(array, mid, size, cpy);

	merge(cpy, size, first, mid, array);
}
/**
 * copy_array - Copies array of int.
 * @arr: Array src.
 * @cpy: Array dest.
 * @size : Array size.
 */
void copy_array(int *arr, int *cpy, int size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		cpy[i] = arr[i];
}

/**
 * merge_sort - Creates a partition and copy it.
 * @array: Array.
 * @size : Array size.
 */
void merge_sort(int *array, size_t size)
{
	int *cpy;

	cpy = malloc(sizeof(int) * size - 1);

	if (cpy == NULL)
		return;

	copy_array(array, cpy, size);

	mergeSort(cpy, 0, size, array);
	free(cpy);
}
