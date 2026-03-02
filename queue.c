#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void init_queue(Queue* pq, int size){
	empty_queue(pq);
	pq->size = size;
	
	pq->data = (int*)malloc(sizeof(int)*size);
	
	if(pq->data == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
}

void delete_queue(Queue* pq){
	empty_queue(pq);
	pq->size = 0;
	free(pq->data);
}

void put_in_queue(Queue* pq, int num){
	
	if(is_empty(*pq)){
		pq->data[0] = num;
		pq->start = 0;
		pq->end = 0;
		
		return;
	}
	
	if(is_full(*pq))
		return;
	
	int lim = pq->size - 1;
	skip_right(&(pq->end), lim);
	
	pq->data[pq->end] = num;
}

int call_queue(Queue* pq){
	
	if(is_empty(*pq)){
		perror("Unable to retrieve value from empty queue");
		exit(1);
	}
	
	int num = pq->data[pq->start];
	
	int lim = pq->size - 1;
	skip_right(&(pq->start), lim);
	
	return num;
}

void empty_queue(Queue* pq){
	pq->start = -1;
	pq->end = -1;
}

void skip_right(int* ctrl, int lim){
	*ctrl = (*ctrl == lim)? 0 : *ctrl + 1;
}

void skip_left(int* ctrl, int lim){
	*ctrl = (*ctrl == 0)? lim : *ctrl - 1;
}

bool is_empty(Queue q){
	return (q.start == -1)? true : false;
}

bool is_full(Queue q){
	int lim = q.size - 1;
	int temp = q.end;
	skip_right(&temp, lim);
	
	return (temp == q.start)? true : false;
}