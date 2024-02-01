#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
size_t get_size(void);
void allocate_memory(size_t***, size_t size);
void read_graph(size_t*** graph,size_t size);
void print_graph(size_t** graph, size_t size);
void free_memory(size_t*** graph, size_t size);

int main(void){
	size_t** graph;
	size_t size;

	size = get_size();
	allocate_memory(&graph, size);
	read_graph(&graph, size);
	print_graph(graph, size);
	free_memory(&graph, size);
return EXIT_SUCCESS;
}

size_t get_size(void){
	size_t size;
	do{
			printf("How many vertices does the graph have?");
			scanf("%zu", &size);
			getchar();
	}while(size<1);

	return size;
}

void allocate_memory(size_t*** graph, size_t size){
	
	*graph = (size_t** )malloc(sizeof(size_t* ) * size);
	if (*graph == NULL) {
		free(*graph);
		perror("Failed to allocate memory for graph\n");
		exit(EXIT_FAILURE);
	}
	for(size_t i = 0; i < size; ++i){
		(*graph)[i] = (size_t* )malloc(sizeof(size_t) * size);
		if (graph[i] == NULL){
			fprintf(stderr, "Failed to allocate memory for graph[%zu]\n", i);
			while(true){
				free((*graph)[i--]);
				if(i){
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}

void read_graph(size_t*** graph, size_t size){
	
	 
	  for(size_t i = 0; i < size; ++i){
	  	do{
	  		printf("Is vertex %zu connected to itself? ", i);
	 			scanf("%zu", &(*graph)[i][i]);
			}while((*graph)[i][i] != 1 && (*graph)[i][i] != 0);
	 	}
	  
		for(size_t i = 0; i < size; ++i){
			for(size_t j = i+1; j < size; ++j){
					do{
	  				printf("Is vertex %zu connected to vertex %zu? ", i, j);
	 					scanf("%zu", &(*graph)[i][j]);
					}while((*graph)[i][j] != 1 && (*graph)[i][j] != 0);
			}
	 	}
		for(size_t i = 0; i < size; ++i){
			for(size_t j = 0; j < i; ++j){
					do{
	  				printf("Is vertex %zu connected to vertex %zu? ", i, j);
	 					scanf("%zu", &(*graph)[i][j]);
					}while((*graph)[i][j] != 1 && (*graph)[i][j] != 0);
			}
	 	}
		
	 
}
	

void print_graph(size_t** graph, size_t size){
	for(size_t i = 0; i < size; ++i){
		for(size_t j = 0; j < size; j++){
			printf("%zu\t", graph[i][j]);
		}
		printf("\n");
	}

}


void free_memory(size_t*** graph, size_t size){
	for(size_t i = 0; i < size; ++i){
		free((*graph)[i]);
	}
	free(*graph);	
}
