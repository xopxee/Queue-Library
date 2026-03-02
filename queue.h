#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

//Comments, next_idx(), call_and_print

typedef struct{
	int* data;
	int start;
	int end;
	int size;
	
}Queue;

void init_queue(Queue* pq, int size);

void delete_queue(Queue* pq);

void empty_queue(Queue* pq);

void put_in_queue(Queue* pq, int num);

int call_queue(Queue* pq);

void skip_right(int* ctrl, int lim);

void skip_left(int* ctrl, int lim);

bool is_empty(Queue q);

bool is_full(Queue q);

#endif