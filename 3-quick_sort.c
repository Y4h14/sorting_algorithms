#include "sort.h"

/**
 * quick_sort - sorts an array using the quick sort algorithm
 * and Lomuto partition scheme
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: (void)
 */

void quick_sort(int *array, size_t size)
{
	if (array == 0 || size < 2)
		return;
	recur_part(array, 0, size - 1, size);
}

/**
 * recur_part - recursive part of the quick sort algorithm
 * @arr: the array to be sorted
 * @lo: lowest index
 * @hi: highest index
 * @size: the size of the array
 * Return: (void)
 */
void recur_part(int *arr, int lo, int hi, size_t size)
{
	int pivotIndex = 0;

	/*This is where the magic happens*/
	if (lo < hi)
	{
		pivotIndex = lomuto_partition(arr, lo, hi, size);
		recur_part(arr, lo, pivotIndex - 1, size);
		recur_part(arr, pivotIndex + 1, hi, size);
	}
}
/**
 * lomuto_partition - parts the array into two subarrays:
 * left subarray is less or equal than the pivot
 * right subarray is greater or equal than the pivot
 * @low: low index
 * @high: high index
 * @array: the array be partitioned
 * @size: the size of the array
 * Return: the index of the pivot
 */
unsigned int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivotIndex = low, placeholder = 0, j = low;
	int pivot = array[high];

	while (j < high)
	{
		if (array[j] < pivot)
		{
			if (pivotIndex != j)
			{
				placeholder = array[pivotIndex];
				array[pivotIndex] = array[j];
				array[j] = placeholder;
				print_array(array, size);
			}
			pivotIndex++;
		}
		j++;
	}

	if (array[pivotIndex] != array[high])
	{
		placeholder = array[pivotIndex];
		array[pivotIndex] = array[high];
		array[high] = placeholder;
		print_array(array, size);
	}
	return (pivotIndex);
}
