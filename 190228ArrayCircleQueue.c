//queue
#include <stdio.h>
#include <stdlib.h>
typedef struct queue {
	int capacity, size, front, rear;
	int *ptr;
}Queue;
void CreateQueue(Queue** queue, int capacity) {
	(*queue) = (Queue*)malloc(sizeof(Queue));
	(*queue)->ptr = (int *)malloc(sizeof(int)*capacity);
	(*queue)->capacity = capacity;
	(*queue)->size = 0;
	(*queue)->front = 0;
	(*queue)->rear = capacity-1;
}
void DestroyQueue(Queue* queue) {
	free(queue->ptr);
	free(queue);
}
void Enqueue(Queue* queue, int data) {
	if (queue->size != queue->capacity) {
		queue->rear = (queue->rear + 1) % queue->capacity;
		queue->ptr[queue->rear] = data;
		queue->size++;
	}
	else {
		printf("queue is full\n");
		return;
	}
}
int Dequeue(Queue* queue) {
	if (queue->size) {
		int data = queue->ptr[queue->front];
		queue->front = (queue->front + 1) % queue->capacity;
		queue->size--;

		return data;
	}
	else {
		printf("queue is empty\n");
	}
}
void PrintQueue(Queue* queue) {
	int index = queue->front;

	for (int i = 0; i < queue->size; i++) {
		printf("%d ", queue->ptr[index]);
		index = index + 1 % queue->capacity;
	}
}
int main(void) {
	Queue* queue = NULL;
	CreateQueue(&queue, 6);
	Enqueue(queue, 0);
	Enqueue(queue, 1);
	Enqueue(queue, 2);
	Enqueue(queue, 3);
	Dequeue(queue);
	
	PrintQueue(queue);
	getchar();
}
