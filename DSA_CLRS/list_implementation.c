#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node {
  int64_t data;
  struct node *next;
	struct node *prev;
}node;
node *mknode(int64_t val);
void insert_beginning(node **head, int64_t val);
int main(void){

	node *head = NULL;
			
return EXIT_SUCCESS;
}
node *mknode(int64_t val){
	node *new = NULL;
	new = malloc(sizeof(node));
	new->data = val;
	new->next = NULL;
	new->prev = NULL;
	return new;
}
void insert_beginning(node **head, int64_t val){
	node *new = mknode(val);
	new->next = head;	
}
