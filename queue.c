#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node * next;
}Node;

typedef struct queue {
	Node * front;
	Node * rear;
	int size;
}listQueue;


void InitQueue(listQueue * queue) { //이것두 잘모르겠음.
	//(* queue) = (listQueue *)malloc(sizeof(listQueue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}
void addNode(listQueue * queue, int data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (queue->size == 0) {
		//queue->front->next = newNode;
		queue->front = newNode; //이것두
		queue->rear = newNode;
	}
	else {
		//Node * tmp = queue->front;
		newNode->next = queue->rear;
		queue->rear = newNode;
	}
	queue->size++;
}
void removeNode(listQueue * queue) {
	Node * tmp = NULL;
	if (queue->size == 0) {
		exit(1);
	}
	else {
		Node * tmp = queue->rear;
		/**for (tmp = queue->rear; tmp->next == queue->front; tmp = tmp->next)
		{
			
		}**/
		for (int i = 0; i < queue->size - 2; i++) {
			tmp = tmp->next;
		}
		//free(queue->front);
		free(tmp->next);
		queue->front = tmp;
	}
	queue->size--;
}
Node* peek(listQueue * queue) {
	if (queue->front == NULL) {
		exit(1);
	}
	return queue->front;
}
void printQ(listQueue * queue) { //front부터 출력하고 싶다
	Node * tmp = queue->rear;
	for (int i = 0; i < queue->size; i++) { //-1이 아니
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
int main(void) {
	listQueue queue;
	InitQueue(&queue);
	addNode(&queue, 10);
	addNode(&queue, 20);
	addNode(&queue, 30);
	addNode(&queue, 40);
	addNode(&queue, 50);
	printQ(&queue);
	printf("%d\n", peek(&queue)->data);
	removeNode(&queue);
	printQ(&queue);
	printf("%d\n", peek(&queue)->data);
}
