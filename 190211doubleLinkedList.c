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
	struct node* tail;
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

	if (isEmpty(list)) { 
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;
		list->head = newNode;
		list->tail = newNode;
		list->size++;
	}
	else {
		newNode->data = data;
		list->head->prev = newNode;
		newNode->prev = NULL;
		newNode->next = list->head;
		list->head = newNode;
		list->size++;
	}
}
void mid_add(List* list, int index, int data) {
	Node* tmp = list->head; 
	int i = 0;
	while (i<index-1) {
		tmp = tmp->next;
		i++;
	}
	if (index == 0) { //맨처음
		add(list, data);
	}
	else if (index == list->size) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = list->tail;
		list->tail->next = newNode;
		list->tail = newNode;
	}
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->prev = tmp;
		newNode->next = tmp->next;
		tmp->next = newNode;
		tmp->next->prev = newNode;
	}
	list->size++;
}
Element remove(List* list) {
	Node* tmp = list->head;
	//free(tmp);
	int r_data = tmp->data;
	list->head = list->head->next;
	free(tmp);
	list->size--;

	return r_data;
}
Bool isEmpty(List* list) {
	return list->size == 0;
}
void headprintList(List* list) {
	for (Node* tmp = list->head; tmp != NULL; tmp = tmp->next) {
		printf("%d ", tmp->data);
	}
	printf("\n");
}
void tailprintList(List* list) {
	for (Node* tmp = list->tail; tmp != NULL; tmp = tmp->prev) {
		printf("%d ", tmp->data);
	}
	printf("\n");
}
int main(void) {
	List* list = init();
	add(list, 10);
	add(list, 20);
	add(list, 30);
	mid_add(list, 0, 40);
	headprintList(list);
	return 0;
}
