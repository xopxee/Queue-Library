#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

//Macro operator that finds the next index   
//based on a set limit and a circular behaviour.
#define NEXT(i) (( (i) == lim )? 0 : (i) + 1) 

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

void call_and_print(Queue* pq);

bool is_empty(Queue q);

bool is_full(Queue q);

#endif