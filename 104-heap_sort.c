#include "sort.h"

/**
 * maxHeapEnforcer - recursive function which ensures
 * that the given node follows the max heap property
 * @a: the array in question
 * @heapS: size of the heap
 * @trg: target node from where the test starts
 * @arrS: size of the array
 * Return: (void)
 */
void maxHeapEnforcer(int *a, int trg, size_t heapS, size_t arrS)
{
	unsigned int max = trg, leftCh = trg * 2 + 1;
	unsigned int rightCh = trg * 2 + 2;

	if (leftCh < heapS && a[leftCh] > a[max])
		max = leftCh;

	if (rightCh < heapS && a[rightCh] > a[max])
		max = rightCh;

	if ((unsigned int) trg != max)
	{
		heapSwap(a, (int) trg, (int) max, arrS);
		maxHeapEnforcer(a, max, heapS, arrS);
	}
}
/**
 * heapSwap - swaps two nodes in a binary heap
 * @array: the array in question
 * @first: the index of the first element
 * @second: the index of the second element
 * @size: the size of the array
 * Return: (void)
 */
void heapSwap(int *array, int first, int second, size_t size)
{
	int placeholder = 0;

	if (first != second)
	{
		placeholder = array[first];
		array[first] = array[second];
		array[second] = placeholder;
		print_array(array, size);
	}
}
/**
 * heap_sort - sorts an array using heap sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: (void)
 */
void heap_sort(int *array, size_t size)
{
	unsigned int arraySize = size;
	int i = 0;

	if (array == NULL || size < 2)
		return;

	i = size / 2 - 1;
	while (i >= 0)
	{
		maxHeapEnforcer(array, i, size, arraySize);
		i--;
	}

	i = size - 1;
	while (i > 0)
	{
		heapSwap(array, 0, i, arraySize);
		maxHeapEnforcer(array, 0, i, arraySize);
		i--;
	}
}
