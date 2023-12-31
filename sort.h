#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*printing functions*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*sorting algorithms*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(listint_t **list, listint_t *node1, listint_t *node2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
unsigned int lomuto_partition(int *array, int low, int high, size_t size);
void recur_part(int *arr, int lo, int hi, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, size_t size, int *left,
size_t left_size, int *right, size_t right_size);
void maxHeapEnforcer(int *a, int trg, size_t heapS, size_t arrS);
void heapSwap(int *array, int first, int second, size_t size);
void heap_sort(int *array, size_t size);
#endif /*_SORT_H_*/
