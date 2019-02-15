#include "LinkedQueue.h"

int main(void) {
	LinkedQueue* Queue = NULL;
	LQ_CreateQueue(&Queue);
	LQ_Enqueue(Queue, LQ_CreateNode("hello"));
	LQ_Enqueue(Queue, LQ_CreateNode("world"));
	LQ_Enqueue(Queue, LQ_CreateNode("every"));
	LQ_Enqueue(Queue, LQ_CreateNode("body~"));

	printf("front : %s\n", Queue->front->data);

	printf("Dequeue : %s\n", LQ_Dequeue(Queue)->data);

	printf("front : %s\n", Queue->front->data);

	
	//LQ_DestroyQueue(Queue);

}
