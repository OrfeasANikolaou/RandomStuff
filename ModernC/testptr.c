#include <stdio.h>
#include <stdlib.h>

int main(void){

	int* ptr = &(int){1, 3,};
	size_t size = sizeof(ptr)/sizeof(ptr[0]);
	for (size_t i = 0; i < size; ++i)
		printf("%d\n", ptr[i]);

	return EXIT_SUCCESS;
}
