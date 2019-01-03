#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node * link;
} Node;
Node * top;

void Push(int data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = top;
	top = newNode;
	
}
void Pop() {
	Node * tmp = top;
	
	top = tmp->link;
}
int Pick() {
	if (top == NULL) {
		exit(1);
	}
	return top->data;
}
int IsEmpty() {
	if (top == NULL) {	
		return 0;
	}
	else {
		return 1;
	}
}
void PrintStack() {
	Node* tmp;
	if (1 == IsEmpty()) {
		for (tmp = top; tmp != NULL; tmp = tmp->link)			
			printf("%d ", tmp->data);
	}
	else {
		printf("저장된 데이터가 없습니다.");
	}
}
int main(void) {
	Push(10);
	Push(20);
	Push(30);
	Push(40);
	printf("top : %d\n", Pick());
	Pop();
	printf("top : %d\n", Pick());
	PrintStack();
	return 0;
