#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort
 * algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: (void)
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, minIndex = 0, j = 0;
	int placeholder = 0;

	/*Can't sort an empty array*/
	if (array == NULL)
		return;
	/*Iterate through the array*/
	while (i < size)
	{
		/*Assume the current element as the min*/
		minIndex = i;
		j = i + 1;
		/*Test the assumption against the other elements*/
		while (j < size)
		{
			/*If a new min is found, store its index*/
			if (array[minIndex] > array[j])
				minIndex = j;
			j++;
		}
		/*Perform a swap if a new min was found*/
		if (minIndex != i)
		{
			placeholder = array[i];
			array[i] = array[minIndex];
			array[minIndex] = placeholder;
			print_array(array, size);
		}
		i++;
	}
}
