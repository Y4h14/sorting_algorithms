#include "sort.h"
/**
 * bubble_sort - sorting array using bubble algorithm
 * @array: the array to be sorted
 * @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int i, temp;
	bool unsorted = true;

	while (unsorted == true)
	{
		unsorted = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				unsorted = true;
				print_array(array, size);
			}
		}
	}
}
