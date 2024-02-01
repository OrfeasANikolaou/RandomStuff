#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
void swap(int64_t *a, int64_t *b);
size_t partition(size_t const len, int64_t arr[len], size_t const p, size_t const r);
void quicksort(size_t const len, int64_t arr[len], size_t const p, size_t const r);

int main(void){
	int64_t arr[10] = {54, -455, 45, 54, 0, 0, 45, 1, 5, 43, };
	puts("OLD");
	for (size_t i = 0; i < 10; ++i){
		printf("A[%zu] = %ld\n", i, arr[i]);
	}
	quicksort(10, &arr[0], 0, 9);
	puts("NEW");
	for (size_t i = 0; i < 10; ++i){
		printf("A[%zu] = %ld\n", i, arr[i]);
	}
return EXIT_SUCCESS;
}

void swap(int64_t *a, int64_t *b){
	int64_t t = *a;
	*a = *b;
	*b = t;
}
//size_t rand_partition(size_t const len, int64_t arr[len], size_t const p, size_t const r){
//	i = random(p, r);
//	swap(arr[i], arr[r]);
//	ITS LITERALLY JUST SWAP ARR[RAND] WITH ARR[R]
//	partition(len, &arr[0], p, r
//}
size_t partition(size_t const len, int64_t arr[len], size_t const p, size_t const r){
	int64_t pivot = arr[r];
	int64_t i = p - 1;
	for (size_t j = p; j < r; ++j){
		if (arr[j] <= pivot){
			++i;
			swap(&arr[i], &arr[j]);
			
		}
	}	
	swap(&arr[i + 1], &arr[r]);
	return i + 1;
}
void quicksort(size_t const len, int64_t arr[len], size_t const p, size_t const r){
	if (p < r){
		//size_t q = rand_partition(len, &arr[0], p, r);
		size_t q = partition(len, &arr[0], p, r);
		quicksort(len, &arr[0], p, q-1);
		quicksort(len, &arr[0], q+1, r);
	}	
}
