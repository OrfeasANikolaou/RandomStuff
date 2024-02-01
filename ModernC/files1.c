#include <stdio.h>
#include <stdlib.h>

int main(void){

FILE* file1 = fopen("file1.txt", "a");
if (!file1){
	perror("fopen failed");
	return EXIT_FAILURE;
}
fputs("feeling fine today\n", file1);


return EXIT_SUCCESS;
}
