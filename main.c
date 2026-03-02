#include <stdio.h>
#include "queue.h"

int main(){
	
	Queue q;
	init_queue(&q, 10);
	
	for(int i = 0; i < 10; i++){
		put_in_queue(&q, i);
	}
	
	for(int i = 0; i < 4; i++){
		printf("%d ", call_queue(&q));
	}
	printf("\n");
	
	for(int i = 0; i < 4; i++){
		put_in_queue(&q, i);
	}
	
	for(int i = 0; i < 10; i++){
		printf("%d ", call_queue(&q));
	}
	printf("\n");
	
	delete_queue(&q);
	
	return 0;
}