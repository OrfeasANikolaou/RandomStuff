#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct queue{
	int64_t head, tail;
	size_t size;
	int64_t *val;
}queue;

queue *mk_queue(size_t size);
int64_t get_data(void);
bool is_empty(queue const *q);
bool is_full(queue const *q);
void enqueue(queue *q, int64_t const data);
void dequeue(queue *q);
void print_queue(queue const *q);
void print_indexes(queue const *q);
bool in_range(queue const *q, int64_t const i);
int main(void){
	int64_t select;
	int64_t sz;
	int64_t data;
	queue *q = NULL;
	fprintf(stdout, "Enter desired queue size: ");
	scanf("%ld", &sz);
	q = mk_queue(sz);
	do{
		fprintf(stdout, "1: Enqueue\n"
										"2: Dequeue\n"
										"3: Is_empty\n"
										"4: Is_full\n"
										"5: Print_queue\n"
										"6: Print_indexes\n");
		scanf("%ld", &select);
		switch(select){
			case 1:
				data = get_data();
				enqueue(q, data);
			break;
			case 2:
				dequeue(q);
			break;
			case 3:
				if ( is_empty(q) )
					fprintf(stdout, "The queue is empty\n");
				else
					fprintf(stdout, "The queue is not empty\n");
			break;
			case 4:
				if ( is_full(q) )
					fprintf(stdout, "The queue is full\n");
				else
					fprintf(stdout, "The queue is not full\n");
			break;
			case 5:
				print_queue(q);
			break;
			case 6:
				print_indexes(q);
			break;
		}
	}while(1);
	return EXIT_SUCCESS;
}

queue *mk_queue(size_t size){
	queue *q = NULL;
	q = malloc(sizeof(queue));
	q->val = malloc(sizeof(int64_t) * size);
	q->size = size;
	q->head = -1;
	q->tail = -1;
	return q;
}
int64_t get_data(void){
	int64_t ret;
	int32_t clear_buffer;
	printf("Give value: ");
	scanf("%ld", &ret);
	while( (clear_buffer = getchar() != '\n') && clear_buffer != EOF);
	return ret;
}
bool is_full(queue const *q){
	if ( (q->head == q->tail+1) ||
			(0 == q->head && q->size-1 == q->tail) ) return true;
	return false;
}
bool is_empty(queue const *q){
	if (-1 == q->head ||
			q->head > q->tail) return true;
	return false;	
}
void enqueue(queue *q, int64_t const data){
	if (is_full(q)){
		fprintf(stderr, "Cannot insert element into a full queue\n");
	}
	else {
		if (q->head < 0 || q->head == q->size) q->head = 0;
		q->val[++q->tail] = data;
	}
}
void dequeue(queue *q){
	if(is_empty(q)){
		fprintf(stderr, "Cannot remove element from empty queue\n");
	}
	else {
		++q->head;
		if (q->head == q->size){
			q->head = -1;
		}
	}
}
void print_queue(queue const *q){
	if ( is_empty(q) ) {
		fprintf(stderr, "Cannot print empty queue\n");
	}
	else {
					int64_t i = q->head;
					int64_t cnt = 0;
					while (in_range(q, i) && cnt < q->size) {
						printf("q[%ld] = %ld\n", i, q->val[i]);
						i = (i + 1) % q->size;
						++cnt;
				}
	}
}
void print_indexes(queue const *q){
	fprintf(stdout, "Head: %ld\n", q->head);
	fprintf(stdout, "Tail: %ld\n", q->tail);
}
bool in_range(queue const *q, int64_t const i){
	bool ret = false;
	if ( (q->head <= i && i <= q->tail) || 
			 (q->tail <= i && i <= q->head) ) ret = true;
	return ret;
}
