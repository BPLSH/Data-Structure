#include<stdio.h>
#include<stdlib.h>
#define Bool int
typedef struct queue {
	int * arr;
	int front, rear, size, capacity;
}Queue;
Queue* CreateQueue(int capacity) {
	Queue* queue = (Queue*)malloc(sizeof(queue));
	//Queue* queue = (Queue*)calloc(capacity, sizeof(int));
	queue->arr = (int *)calloc(capacity, sizeof(int));
	//queue->arr = NULL;  ?
	queue->capacity = capacity;
	queue->size = 0;
	queue->front = 0;
	queue->rear = capacity-1;

	return queue;
}
void Enqueue(Queue* queue, int data) {
	if (IsFull(queue)) {
		printf("데이터가 꽉 찼습니다.\n");
		return;
	}
	queue->rear = (queue->rear + 1) / queue->capacity;
	queue->arr[queue->rear] = data;
	queue->size++;
	printf("%d ", queue->arr[queue->rear]);
}
int* Dequeue(Queue* queue) {
	if (IsEmpty(queue)) {
		printf("지울 데이터가 없습니다.\n");
		exit(1);
	}
	int* del = &queue->arr[queue->front];
	queue->front = queue->front + 1; //++;
	queue->size--;
	return del;
}
int* Front(Queue * queue) {
	int* front = &(queue->arr[(queue->front)]); //상수만 되는거 아닌가? 변수 가능?
	return front;
}
int* Rear(Queue * queue) {
	int* rear = &queue->arr[queue->rear];
	return rear;
}
Bool IsFull(Queue* queue) {
	return queue->size == queue->capacity;
}
Bool IsEmpty(Queue* queue) {
	return queue->size == 0;
}
int QueueSize(Queue* queue) {
	return queue->size;
}
int QueueFront(Queue * queue) {
	return queue->front;
}
int main(void) {
	int capacity = 10;
	int* del = NULL,* front =NULL, *rear = NULL;
	
	Queue* queue = CreateQueue(capacity);
	Enqueue(queue, 10);
	Enqueue(queue, 20);
	Enqueue(queue, 30);
	Enqueue(queue, 40);
	Enqueue(queue, 50);
	Enqueue(queue, 60);
	Enqueue(queue, 70);
	Enqueue(queue, 80);
	Enqueue(queue, 90);
	Enqueue(queue, 100);
	front = Front(queue);
	rear = Rear(queue);
	printf("\n");
	printf("%d", *front);
	printf("%d", *rear);
}
