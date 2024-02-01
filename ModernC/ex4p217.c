#include <stdio.h>
#include <stdlib.h>

extern unsigned i = 1;

int main(void){

	unsigned i = 2;
	if (i) {
		extern unsigned i;
		printf("%u\n", i);
	}
	else {
		printf("%u\n", i);
	}

	return EXIT_SUCCESS;
}
