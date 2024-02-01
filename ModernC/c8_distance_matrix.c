#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
uint16_t get_size(void);
void allocate_memory(uint16_t***, uint16_t size);
void read_graph(uint16_t*** graph,uint16_t size);
void print_graph(uint16_t** graph, uint16_t size);
void free_memory(uint16_t*** graph, uint16_t size);

int main(void){
	uint16_t** graph;
	uint16_t size;

	size = get_size();
	allocate_memory(&graph, size);
	read_graph(&graph, size);
	print_graph(graph, size);
	free_memory(&graph, size);
return EXIT_SUCCESS;
}

uint16_t get_size(void){
	uint16_t size;
	do{
			printf("How many vertices does the graph have?");
			scanf("%hu", &size);
			getchar();
	}while(size<1);

	return size;
}

void allocate_memory(uint16_t*** graph, uint16_t size){
	
	*graph = (uint16_t** )malloc(sizeof(uint16_t* ) * size);
	if (*graph == NULL) {
		free(*graph);
		perror("Failed to allocate memory for graph\n");
		exit(EXIT_FAILURE);
	}
	for(uint16_t i = 0; i < size; ++i){
		(*graph)[i] = (uint16_t* )malloc(sizeof(uint16_t) * size);
		if (graph[i] == NULL){
			fprintf(stderr, "Failed to allocate memory for graph[%hu]\n", i);
			while(true){
				free((*graph)[i--]);
				if(i){
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}

void read_graph(uint16_t*** graph, uint16_t size){
	
	  for(uint16_t i = 0; i < size; ++i){
			(*graph)[i][i] =USHRT_MAX;
		}
		for(uint16_t i = 0; i < size; ++i){
			for(uint16_t j = i+1; j < size; ++j){
					
	  				printf("Distance from vertex [%hu] to vertex [%hu]? ", i, j);
	 					scanf("%hu", &(*graph)[i][j]);
			}
	 	}
		for(uint16_t i = 0; i < size; ++i){
			for(uint16_t j = 0; j < i; ++j){
	  				printf("Distance from vertex [%hu] to vertex [%hu]? ", i, j);
	 					scanf("%hu", &(*graph)[i][j]);
			}
	 	}
		
	 
}
	

void print_graph(uint16_t** graph, uint16_t size){
	for(uint16_t i = 0; i < size; ++i){
		for(uint16_t j = 0; j < size; j++){
			printf("%10hu\t", graph[i][j]);
		}
		printf("\n");
	}

}


void free_memory(uint16_t*** graph, uint16_t size){
	for(uint16_t i = 0; i < size; ++i){
		free((*graph)[i]);
	}
	free(*graph);	
}
