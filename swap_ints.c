#include "sort.h"

/**
 * swap_ints - Swaps the two  given integers
 * @a: The first integer
 * @b: The second integer
 */

void swap_ints(int *a,int *b)
{
	int tmp;
	tmp = *a; 
	*a = *b;
	*b = tmp;
}
