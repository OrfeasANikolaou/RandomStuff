#include <stdio.h>
#include <stdlib.h>

int main(void){

	char arg = getchar();
/*
 * Just switch statement
 */
	switch (arg) {
		case 'm': puts("M");
							break;
		case 'r': puts("R");
							break;
		case 'j': puts("J");
							break;
		case 'c': puts("C");
							break;
		default: puts("DEF");
	
	}

return EXIT_SUCCESS;
}
