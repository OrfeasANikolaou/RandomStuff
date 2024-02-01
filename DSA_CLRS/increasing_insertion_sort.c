#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int n, int arr[n]);
int main(void){
	
	int a[10] = { 34, 34, 7, 4, 7, 2346, 65, 3, -34, 0};

	puts("OLD");
	for(int i = 0; i < 10; ++i)
		printf("a[%d] = %d\n", i, a[i]);

	insertion_sort(10, &a[0]);
	puts("NEW");
	for(int i = 0; i < 10; ++i)
		printf("a[%d] = %d\n", i, a[i]);

	return EXIT_SUCCESS;
}
void insertion_sort(int n, int arr[n]){

	for(int i = 1; i < n; ++i){
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			arr[j] = key;
			--j;
		}
	}
}
