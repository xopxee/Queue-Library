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
	pq->end = NEXT(pq->end);
	
	pq->data[pq->end] = num;
}

int call_queue(Queue* pq){
	
	if(is_empty(*pq)){
		perror("Unable to retrieve value from empty queue");
		exit(1);
	}
	
	int num = pq->data[pq->start];
	
	if(pq->start == pq->end){
		empty_queue(pq);
		return num;
	}
	
	int lim = pq->size - 1;
	pq->start = NEXT(pq->start);
	
	return num;
}

void call_and_print(Queue* pq){
	
	if(is_empty(*pq)){
		printf("Queue is empty\n");
		return;
	}
	
	while(!is_empty(*pq)){
		
		printf("%d ", call_queue(pq));
	}
	printf("\n");
}

void empty_queue(Queue* pq){
	pq->start = -1;
	pq->end = -1;
}

bool is_empty(Queue q){
	return (q.start == -1)? true : false;
}

bool is_full(Queue q){
	
	int lim = q.size - 1;
	return (NEXT(q.end) == q.start)? true : false;
}