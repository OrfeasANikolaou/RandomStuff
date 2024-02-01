#include <stdio.h>

int main(void){

	double A[5] = {0};

	printf("Array size: %zu\n", (sizeof(A)/sizeof(A[0])));

return 0;
}
