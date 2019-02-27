//singleLinkedList
#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode{ 
	struct tagNode* next;
	int data;
}Node;
Node* head = NULL; 
Node* CreateNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}
void InsertNode(Node* newNode) {
	
	if (head->next == NULL) { 
		head->next = newNode;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}
Node* RemoveNode(int data) { 
	if (head == NULL) {
		printf("head is null");
		return NULL;
	}
	if (data == head->data) {
		Node* tmp = head;
		head = head->next;
		return tmp;
	}
	else {
		for (Node* tmp = head; tmp->next != NULL; tmp = tmp->next) { //tmp의 범위
			if (data == tmp->next->data) {
				Node* cur = tmp->next;
				tmp->next = cur->next;
				return cur;
			}
		}
		return NULL;
	}
}
void DestroyNode(Node* node) { 
	if (node == NULL) {
		return;
	}
	free(node);
}
void PrintList() {
	for (Node* tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("%d ",tmp->data);
	}
	printf("\n");
}
int main(void) {
	head = CreateNode(10);

	InsertNode(CreateNode(20));
	InsertNode(CreateNode(30));
	InsertNode(CreateNode(40));
	InsertNode(CreateNode(50));
	InsertNode(CreateNode(60));
	InsertNode(CreateNode(70));
	InsertNode(CreateNode(80));
	InsertNode(CreateNode(90));
	InsertNode(CreateNode(100));

	PrintList();
	DestroyNode(RemoveNode(10));
	PrintList();
	printf("%d", head->data);
	getchar();
}
