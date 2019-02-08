//arrayqueue
#include <stdio.h>
#include <stdlib.h>
#define Bool int
#define TRUE 1
#define FALSE 0

typedef struct queue {
	int size,front,rear,capacity;
	int *arr;

}Queue;
Queue* init(int capacity) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->arr = (int*)malloc(capacity * sizeof(int));
	queue->front = 0;
	queue->rear = capacity-1;
	queue->capacity = capacity;
	queue->size = 0; 
	
	return queue;
}
void enqueue(Queue* queue, int data) {
	if (isFull(queue)) {
		printf("data is full");
		return;
	}
	queue->rear = (queue->rear+1) % queue->capacity;
	queue->arr[queue->rear] = data;
	queue->size++;
}
void dequeue(Queue* queue){
	if (isEmpty(queue)) {
		printf("data is null");
		return;
	}
	int front = queue->front;
	queue->front = queue->front + 1 % queue->capacity;
	queue->size--;

}
int front(Queue* queue) {
	return queue->arr[queue->front];
}
Bool isEmpty(Queue* queue) {
	return queue->size == 0;
}
Bool isFull(Queue* queue) {
	return queue->size == queue->capacity;
}
void printQueue(Queue* queue) { //질문
	for (int i = queue->front; i <= queue->rear; i++) {
		printf("%d ", queue->arr[i]);
	}
}
int main(void) {
	int capacity = 10;
	Queue* queue = init(capacity);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	enqueue(queue, 50);
	dequeue(queue);
	printQueue(queue);
}
