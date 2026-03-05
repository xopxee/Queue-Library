#include <stdio.h>
#include "queue.h"

int main(){
	
	Queue q;
	init_queue(&q, 10);
	
	for(int i = 0; i < 13; i++){
		put_in_queue(&q, i);
	}
	
	call_and_print(&q);
	
	put_in_queue(&q, 37);
	
	call_and_print(&q);
	call_and_print(&q);
	
	delete_queue(&q);
	
	return 0;
}

