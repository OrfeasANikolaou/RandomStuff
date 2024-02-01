#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
size_t left_node(size_t index);
size_t right_node(size_t index);
size_t parent_node(size_t index);
void min_heapify(size_t len, int arr[len], size_t i);
void swap(int*, int*);
void build_min_heap(size_t len, int arr[len]);
void print_heap(size_t len, int arr[len]);
// IN THIS IMPLEMENTATION, IM ASSUMING ARR LEN == HEAP SIZE
int main(void){
	int a[10] = { 9, 21, 8, 4, 8, 0, -4, 1, 19, 69, };
	build_min_heap(10, &a[0]);
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

void min_heapify(size_t len, int arr[len], size_t i){	
	size_t l_index = left_node(i);
	size_t r_index = right_node(i);
	size_t smallest=i;
	if (l_index < len && arr[l_index] < arr[smallest]){
		smallest = l_index; 
	}
	if (r_index < len && arr[r_index] < arr[smallest]){
		smallest = r_index;
	}
	if (smallest != i){
		swap(&arr[smallest], &arr[i]);
		min_heapify(len, arr, smallest); // runs on previous position of the smallest, where now i is 
	}
}
void build_min_heap(size_t len, int arr[len]){
	for (size_t i = (len / 2); i > 0; --i){
		min_heapify(len, &arr[0], i-1);
	}
}
void print_heap(size_t len, int arr[len]){

	for (size_t i = 0; i < len; ++i){
		
		printf("Index %zu: %02d\n",i, arr[i]);
	}	
	puts("");
}
