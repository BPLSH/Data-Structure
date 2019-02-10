//DoubleLinkedList
#include <stdio.h>
#include <stdlib.h>
#define Bool int
#define TRUE 1
#define FALSE 0
#define Element int

typedef struct node {
	int data;
	//int index;
	struct node* prev;
	struct node* next;
}Node;
typedef struct list {
	int size;
	struct node* head;
}List;
List* init() {
	List* list = (List*)malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;

	return list;
}
void add(List* list, int data) {
	if (list == NULL) {
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (isEmpty(list)) {
		newNode->next = NULL;
	}
	else {
		newNode->next = list->head;
	}
	list->head = newNode;
	list->size++;
}
Element remove(List* list) {
	if (isEmpty(list)) {
		printf("list is null");
		exit(1);
	}
	Node* tmp = list->head;
	free(tmp);
	list->head = list->head->next;
	list->size--;
}
Bool isEmpty(List* list) {
	list->size == 0;
}
void printList(List* list) {
	for (Node* tmp = list->head; tmp != NULL; tmp = tmp->next) {
		printf("%d ", tmp->data);
	}
}
int main(void) {
	List* list = init();
	add(list, 10);
	add(list, 20);
	printList(list);
	return 0;
}
