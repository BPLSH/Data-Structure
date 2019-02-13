//queue 
#include <stdio.h>
#include <stdlib.h>
#define Bool int
#define TRUE 1
#define FALSE 0
#define ElementType int
typedef struct tagNode {
	ElementType Data;
}Node;
typedef struct tagCircularQueue {
	int Capacity, Front, Rear;
	Node* Nodes;
}CircularQueue;
void CQ_CreateQueue(CircularQueue** Queue, int Capacity) {
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node)*Capacity+1);
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}
void CQ_DestroyQueue(CircularQueue* Queue) {
	free(Queue->Nodes);
	free(Queue);
}
void CQ_Enqueue(CircularQueue* Queue, ElementType Data) {
	
	if (Queue->Rear == Queue->Capacity) {
		Queue->Rear = 0;

	}

	Queue->Nodes[Queue->Rear].Data = Data;
	Queue->Rear++;
}
ElementType CQ_Dequeue(CircularQueue* Queue) {
	if (Queue->Front == Queue->Capacity) {
		Queue->Front = 0;
	}
	ElementType Data = Queue->Nodes[Queue->Front].Data;
	Queue->Front++;
	
	return Data;
}
int CQ_IsEmpty(CircularQueue* Queue) {

	return Queue->Front == Queue->Rear;
}
int CQ_IsFull(CircularQueue* Queue) {
	if (Queue->Front < Queue->Rear) {
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	}
	else {
		return Queue->Front == Queue->Rear + 1;
	}
}
Node* CQ_Front(CircularQueue* Queue) {
	return &Queue->Nodes[Queue->Front];
}
int main(void) {
	CircularQueue* Queue = NULL;
	CQ_CreateQueue(&Queue, 10);
}
