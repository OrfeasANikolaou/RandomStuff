#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
size_t left_node(size_t index);
size_t right_node(size_t index);
size_t parent_node(size_t index);
void max_heapify(size_t len, int arr[len], size_t i);
void swap(int*, int*);
void build_max_heap(size_t len, int arr[len]);
void print_heap(size_t len, int arr[len]);
// IN THIS IMPLEMENTATION, IM ASSUMING ARR LEN == HEAP SIZE
int main(void){
	int a[10] = {3,9,6,8,10,0,-4,34,9,1,}; 
	build_max_heap(10, &a[0]);
	print_heap(10, &a[0]);
	return EXIT_SUCCESS;
}

size_t left_node(size_t index){
	return (index<<1)+1;
}
size_t right_node(size_t index){
	return (index<<1)+2;
}
size_t parent_node(size_t index){
	assert(index > 0);
	return (index-1)>>1;
}
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void max_heapify(size_t len, int arr[len], size_t i){	
	size_t l_index = left_node(i);
	size_t r_index = right_node(i);
	size_t largest=i;
	if (l_index < len && arr[l_index] > arr[largest]){
		largest = l_index; 
	}
	if (r_index < len && arr[r_index] > arr[largest]){
		largest = r_index;
	}
	if (largest != i){
		swap(&arr[largest], &arr[i]);
		max_heapify(len, arr, largest); // runs on previous position of the largest, where now i is 
	}
}
void build_max_heap(size_t len, int arr[len]){
	for (size_t i = (len / 2); i > 0; --i){
		max_heapify(len, &arr[0], i-1);
	}
}
void print_heap(size_t len, int arr[len]){

	for (size_t i = 0; i < len; ++i){
		
		printf("Index %zu: %02d\n",i, arr[i]);
	}	
	puts("");
}
