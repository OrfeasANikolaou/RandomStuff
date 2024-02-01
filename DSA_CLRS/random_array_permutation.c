#include <stdio.h>
#include <stdlib.h>
#include <time.h>
size_t random_number_gen(size_t, size_t);

int main(void){
	srand(time(NULL));
	size_t arr_size;
	printf("Enter array size: ");
	scanf("%zu", &arr_size);
	int* arr = malloc(sizeof(int) * arr_size);
	for (size_t i = 0; i < arr_size; ++i){
		arr[i] = rand() - (RAND_MAX / 2);
	}
	
	puts("old array");
	for (size_t i = 0; i < arr_size; ++i){
		printf("%d\n", arr[i]);
	}
	
	for (size_t i = 0; i < arr_size; ++i){
		int temp = arr[i];
		size_t ran = random_number_gen(i,arr_size);
		arr[i] = arr[ran];
		arr[ran] = temp;
	}
	
	puts("new array");
	for (size_t i = 0; i < arr_size; ++i){
		printf("%d\n", arr[i]);
	}

	return EXIT_SUCCESS;
}
size_t random_number_gen(size_t low, size_t high){


	size_t ret = (rand() % high) + low;
	if (ret >= high) ret = high-1;

	return ret;
}
