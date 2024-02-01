#include <stdio.h>
#include <stdlib.h>

int main(void){
	size_t a = 3;
	fprintf(stdout, "%zu\n", (a - 1) >> 1);

	return EXIT_SUCCESS;
}
