#include <stddef.h>
#include <stdio.h>
#include <mylib/data_structures_algorithms/nodes.h>
#include <stdlib.h>
void swap(int* a, int* b);
void max_heapify(size_t const len, int arr[len], size_t i);
void build_max_heap(size_t const len, int arr[len]);
void heapsort(size_t const len, int arr[len]);
void print_heap(size_t const len, int const arr[len]);
int main(void){

	int arr[10] = {3, 9, 6, 8, 10, 0, -4, 34, 9, 1, };
	heapsort(10, &arr[0]);	
	print_heap(10, &arr[0]);
	
	return EXIT_SUCCESS;
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
void max_heapify(size_t const len, int arr[len], size_t i){
	size_t left_index = left_node(i);
	size_t right_index = right_node(i);
	size_t largest = i;
	if (left_index < len &&
			arr[largest] < arr[left_index]){
		largest = left_index;
	}
	if (right_index < len &&
			arr[largest] < arr[right_index]){
		largest = right_index;
	}
	if (largest != i){
		swap(&arr[largest], &arr[i]);
		max_heapify(len, &arr[0], largest);
	}
}
void build_max_heap(size_t const len, int arr[len]){
	for (size_t i = (len / 2); i > 0; --i){
		max_heapify(len, &arr[0], i-1);
	}
}
void print_heap(size_t const len, int const arr[len]){
	for (size_t i = 0; i < len; ++i){
		printf("Index: %zu\tData: %d\n", i, arr[i]);
	}
}
void heapsort(size_t const len, int arr[len]){
	build_max_heap(len, &arr[0]);
	size_t heap_size = len;
	for (size_t i = heap_size - 1; i > 0; --i){
		swap(&arr[0], &arr[i]);
		--heap_size;
		max_heapify(heap_size, &arr[0], 0);
	}	
}
