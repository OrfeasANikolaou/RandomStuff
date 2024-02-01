#include <stdio.h>
#include <stdlib.h>

int main(void){

	if (!freopen("file1.txt", "a", stdout)){
		perror("freopen failed");
		return EXIT_FAILURE;
	}
	puts("im really felling it");


return EXIT_SUCCESS;
}
