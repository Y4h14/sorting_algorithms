#include "sort.h"
/**
 * merge_sort - divides an array into two to sort it
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2, i;
	int *left = array, *right = array + mid;
	int *merged;

	if (size > 1)
	{
		merge_sort(left, mid);
		merge_sort(right, size - mid);
		merged = malloc(size * sizeof(int));
		if (merged == NULL)
			return;
		merge(merged, size, left, mid, right, size - mid);
		for (i = 0; i < size; i++)
			array[i] = merged[i];
		free(merged);
	}
}
/**
 * merge - merges two lists into one sorted list
 * @array: the array to be sorted
 * @size: the size of the array
 * @left: left array
 * @left_size: size of the left array
 * @right: right array
 * @right_size: size of the left array
 */
void merge(int *array, size_t size, int *left,
	size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}
