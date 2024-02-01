#include <stdio.h>
#include <stdlib.h>
void shift(int*, int*, int*);

int main(void){

	int V1 = 20, V2 = 13, V3 = 19;
	puts("OLD");
	printf("%d\n%d\n%d\n", V1, V2, V3);
 	
	shift(&V1, &V2, &V3);
	puts("NEW");
	printf("%d\n%d\n%d\n", V1, V2, V3);
return EXIT_SUCCESS;
}
void shift(int* var1, int* var2, int* var3){
	*var1 = *var2;
	*var2 = *var3;
	*var3 = *var1;
}
