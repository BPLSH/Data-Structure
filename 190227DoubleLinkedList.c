//doubleLinkedList
//더블 vs 싱글
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
	char* data; //문자열 메모리
	struct tagNode* next;
	struct tagNode* prev;
}Node;
Node* head = NULL;
Node* cur = NULL; //어떤게 효율적
Node* CreateNode(const char* data) { //const
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(data) + 1); //동적할당
	strcpy_s(newNode->data, strlen(data) + 1, data);
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}
void AppendNode(Node* newNode) { //노드추가
	if (head != NULL) {
		if (head->next == NULL) {
			head->next = newNode;
			newNode->prev = head;
			cur = newNode;
		}
		else {
			cur->next = newNode;
			newNode->prev = cur;
			cur = newNode;
		}
	}
}
void InsertAfterNode(Node* newNode, const char* data) {
	
	Node* tmp = head;
	
	while (tmp != NULL) {
		if (strcmp(tmp->data, data) == 0) {
			tmp->next->prev = newNode;
			newNode->next = tmp->next;
			newNode->prev = tmp;
			tmp->next = newNode;

			return;
		}
		
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		printf("check data again\n");
		return;
	}
}

Node* RemoveNode(const char* data) {

	if (head != NULL) {
		Node* tmp = head;
		while (tmp != NULL) {
			if (strcmp(tmp->data, data) == 0) {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;

				return tmp;
			}
			tmp = tmp->next;
		}
	}
	printf("check data again\n");
	return NULL;
}

void DestroyNode(Node* node) {
	free(node->data);
	free(node);
}
void PrintList() {
	for (Node* tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("%s ", tmp->data);
	}
	printf("\n");
}
int main(void) {
		
	
	RemoveNode("happy");
	getchar();
	return 0;
}
