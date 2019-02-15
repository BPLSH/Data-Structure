#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** Queue) {
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->front = NULL;
	(*Queue)->rear = NULL;
	(*Queue)->size = 0;
}
void LQ_DestroyQueue(LinkedQueue* Queue) {
	free(Queue);
}
Node* LQ_CreateNode(char* data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = (char*)malloc(sizeof(strlen(data))+1);
	strcpy(NewNode->data, data);
	//NewNode->data = data;
	NewNode->next = NULL;

	return NewNode;
}
void LQ_DestroyNode(Node* NewNode) {
	free(NewNode->data);
	free(NewNode);
}
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode) {
	if (Queue != NULL) {
		if (LQ_IsEmpty(Queue)) {
			Queue->front = NewNode;
			Queue->rear = NewNode;
			Queue->size++;
		}
		else {
			Queue->rear->next = NewNode;
			Queue->rear = NewNode;
			Queue->size++;
		}
	}
}
Node* LQ_Dequeue(LinkedQueue* Queue) {
	if (Queue != NULL) {
		if (LQ_IsEmpty(Queue)) {
			printf("Queue is Empty");
			exit(1);
		}
		else {
			Node* tmp = Queue->front;
			Queue->front = tmp->next;

			return tmp;
		}
	}
}
int LQ_IsEmpty(LinkedQueue* Queue) {
	return Queue->size == 0;
}
