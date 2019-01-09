#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int *array;
	int size, front, rear, capacity;
}Queue;


Queue * createQueue(int capacity) {
	Queue * queue = (Queue *)malloc(sizeof(Queue));
	queue->array = (int *)malloc(sizeof(int)*capacity); //int*
	queue->size = 0;
	queue->front = 0;
	queue->capacity = capacity;
	queue->rear = capacity-1;

	return queue;
}
int isFull(Queue * queue) {
	return queue->size == queue->capacity;
}
int isEmpty(Queue * queue) {
	return queue->size == 0;
}
int front(Queue * queue) {
	return queue->array[queue->front];
}
int rear(Queue * queue) {
	return queue->array[queue->rear];
}
void enqueue(Queue * queue, int data) {
	if (isFull(queue)) {
		printf("데이터가 꽉 찼습니다.\n");
		return;
	}
	queue->rear = (queue->rear + 1) % queue->capacity; //이게 하이라이트
	queue->array[queue->rear] = data;
	queue->size++;
	
}
int dequeue(Queue * queue) {
	if (isEmpty(queue)) {
		printf("데이터가 없습니다.\n");
		return;
	}
	int delete = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return delete;
}

int main(void) {
	int capacity = 10;
	Queue * queue = createQueue(capacity);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	enqueue(queue, 6);
	enqueue(queue, 7);
	enqueue(queue, 8);
	enqueue(queue, 9);
	enqueue(queue, 10);

	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));
	printf("%d \n", dequeue(queue));

	enqueue(queue, 5);
	printf("%d \n", dequeue(queue));

	enqueue(queue, 1);
	
	printf("front : %d \n", front(queue));
	printf("rear : %d \n", rear(queue));
	//getchar(); //왜 입력받지

	return 0;
}
