#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	enum { size_buffer = 30, };
void read_file(char const*);
int main(int argc, char* argv[argc+1]){
	int ret = EXIT_FAILURE;
	char read_stdin[size_buffer];
	if (argc > 1 ){
		int i = 1;
		for (; i < argc; ++i){
			//START OF FUNCTION
			read_file(argv[i]);		
		}
	}
	else{
		puts("Enter file name: ");
		fgets(read_stdin, size_buffer, stdin);
		for(size_t i = 0; i < strlen(read_stdin); ++i){
			if (read_stdin[i] == '\n') read_stdin[i] = '\0';
		}
		read_file(read_stdin);
	}
		
	

	return ret;
}
void read_file(char const* string){
	char line[size_buffer];
	FILE* my_file = fopen(string, "r");
	if(my_file){
		while(fgets(line, size_buffer, my_file)){
			fputs(line, stdout);
		}
		fclose(my_file);
	}
	else exit(EXIT_FAILURE);

}
