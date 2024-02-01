#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){

	char* something = NULL;

	something = (char* )malloc(sizeof(char) * 10);

	strncpy(something, "something", 10);	
	printf("%s\n", something);
free(something);
return 0;
}
