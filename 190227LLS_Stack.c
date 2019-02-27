//stack
#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode {
	int data;
	struct tagNode* next;
}Node;
typedef struct stack {
	struct tagNode* head;
	struct tagNode* top;
}Stack;
void CreateStack(Stack** stack) {
	(*stack) = (Stack*)malloc(sizeof(Stack));
	(*stack)->head = NULL;
	(*stack)->top = NULL;
}
void DestroyStack(Stack* stack) {
	free(stack);
}
Node* CreateNode(int data) { //동적할당도 전역변수?
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data; //?
	newNode->next = NULL;
	return newNode;
}
void DestroyNode(Node* node) {
	free(node);
}
void Push(Stack* stack, Node* newNode) {
	if (stack->head == NULL) {
		stack->head = newNode;
		stack->top = newNode;
	}
	else {
		newNode->next = stack->top;
		stack->top = newNode;
	}
}
Node* Pop(Stack* stack) {
	if (stack->head == NULL) {
		printf("stack is empty\n");
		return NULL;
	}
	Node* tmp = stack->top;
	stack->top = stack->top->next;

	return tmp;
}
Node* Top(Stack* stack) {
	if (stack->top != NULL) {
		return stack->top;
	}
}
void PrintStack(Stack* stack) {
	Node* tmp = stack->top;

	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
int main(void) {
	Stack* stack = NULL;
	CreateStack(&stack);

	Push(stack, CreateNode(1));
	Push(stack, CreateNode(2));
	Push(stack, CreateNode(3));
	Push(stack, CreateNode(4));
	Push(stack, CreateNode(5));
	PrintStack(stack);

	Node* top = Pop(stack);
	DestroyNode(top);
	PrintStack(stack);

	getchar();
	return 0;

}
