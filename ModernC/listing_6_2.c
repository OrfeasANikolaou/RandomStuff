#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	size_t const len = strlen(argv[0]);
	char name[len+1];
	printf("%ld\n", strlen(argv[0]));
	memcpy(name, argv[0], len);
	name[len] = '\0';
	if (!strcmp(name, argv[0])){
		printf("program name \"%s\" successfully copied\n", name);
	}
	else{
		printf("Copying %s leads to a different string %s\n", argv[0], name);
	}


return EXIT_SUCCESS;
}
