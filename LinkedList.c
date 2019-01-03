#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node * next;
}Node;

Node * head;
Node * tail;
void addFirst(int data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	if (head == NULL){ //맨처음
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
	}
	else {
		Node * tmp = head;
		newNode->data = data;
		newNode->next = tmp; //tmp
		head = newNode;
	}
}
void addLast(int data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	if (head == NULL) {
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
		tail = head;
	}
	else {
		newNode->data = data;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}
void addMid(int data, int index) {
	Node * tmp = head;
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	//for (int i = 0; i < index-1; i++) {
	if (index == 1) {
		newNode->next = tmp;
		head = newNode;
	}
	else {
		for (int i = 0; i < index - 2; i++) {
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
}
/**void removeFirst() {
	Node * tmp = head;

	if (head == NULL) {
		exit(1);
	}
	else if(tmp->next == NULL) {
		free(head);
	}

	head = tmp->next;
	free(tmp);
}
void removeLast() {
	Node * tmp = head;
	if (head == NULL) {
		exit(1);
	}
	else if (tmp->next = NULL) {
		free(head);
	}
	
}
void removeMid(int index) {
	Node * tmp = head;
	if (head == NULL) {
		exit(1);
	}
	else if (tmp->next = NULL) {
		free(head);
	}
	else {
		head = tmp->next; //index 1번 지우기
		free(tmp);

		tmp = tmp->next;
		head->next = tmp->next;
		free(tmp); //index 2번 지우기

		tmp = tmp->next;
		tmp->next = tmp->next;
		tmp = tmp->next;

		free(tmp);

	}
}**/
void LPrint() {
	Node * tmp;

	for (tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("%d ", tmp->data);
	}
	printf("\n");
}
int NPrint(int index) {
	Node *tmp = head;
	for (int i = 0; i < index-1; i++) {
		tmp = tmp->next;
	}
	return tmp->data;
}
int main(void) {
	addLast(10);
	addLast(20);
	addLast(30);
	addLast(40);
	addLast(50);
	LPrint();
	
	int i = 1;
	printf("%d번째 인덱스 값 : %d\n",i,NPrint(i));
	
	addMid(5, 1);
	LPrint();
	printf("%d번째 인덱스 값 : %d\n", i, NPrint(i));

	addMid(15, 3);
	LPrint();
	i = 3;
	printf("%d번째 인덱스 값 : %d\n", i, NPrint(i));

	addMid(55, 8);
	LPrint();
	i = 8;
	printf("%d번째 인덱스 값 : %d\n", i, NPrint(i));

	return 0;

}
