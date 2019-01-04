#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node * next;
}Node;

Node * head;
Node * tail;
int size;

void addFirst(int data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	if (head == NULL){ //맨처음
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
		size++;
	}
	else {
		Node * tmp = head;
		newNode->data = data;
		newNode->next = tmp; //tmp
		head = newNode;
		size++;
	}
}
void addLast(int data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	if (head == NULL) {
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
		tail = head;
		size++;
	}
	else {
		newNode->data = data;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
		size++;
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
		size++;
	}
	else {
		for (int i = 0; i < index - 2; i++) {
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
		size++;
	}
}
void removeFirst() {
	Node * tmp = head;

	if (head == NULL) {
		exit(1);
	}
	//free(tmp); 여기다가 하면 안된다.
	head = tmp->next; //free(head) == free(tmp)?
	free(tmp);

	size--;
}
//이게 문제다. tail을 그러면 다 해줘야되나
void removeLast() {
	Node * tmp = head;
	if (head == NULL) {
		exit(1);
	}
	else {
		for (int i = 0; i < size-2; i++) {
			tmp = tmp->next;
		}
		tail = tmp->next;
		free(tail);
		tmp->next = NULL;

		size--;
		
	}
	return tmp->data;
	
}
void removeMid(int index) {
	Node * tmp = head;
	if (head == NULL) {
		exit(1);
	}
	else {
		//언제 그냥 if만 언제 if-else인지 헷갈린다.
		if (index == 1)
		{
			Node * del = tmp;
			free(del);
			
		}
		else {
			for (int i = 0; i < index - 2; i++) {
				tmp = tmp->next;
			}
			Node * del = tmp->next;
			tmp->next = del->next;
			free(del);
		}
		size--;
	}
}
void LPrint() {
	Node * tmp;
	
	for (tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("%d ", tmp->data);
	}
	printf("데이터의 개수 %d\n", size);

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
	removeFirst();
	LPrint();
	removeFirst();
	LPrint();
	removeMid(3);
	LPrint();
	removeMid(2);
	LPrint();
	removeLast();
	LPrint();
	removeLast();
	LPrint();
	
	


	return 0;

}
