//Stack SingleList;
#include <stdio.h>
#include <stdlib.h>
#define Bool int
#define TRUE 1
#define FALSE 0
#define Element int
typedef struct node {
	int data;
	struct node* next;
}Node;
typedef struct stack {
	struct node* top;
	int size;
	int capacity;
}Stack;
Stack* createStack(int capacity) {
	Stack* stack = (Stack*)malloc(capacity*sizeof(Node));
	if (stack == NULL) {
		printf("stack is not created\n");
		exit(1);
	}
	stack->capacity = capacity;
	stack->size = 0;
	stack->top = NULL;
	
	return stack;
}
void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Node is not created");
		return;
	}
	newNode->data = data;
	
	if (isFull(stack)) {
		printf("stack is full");
		return;
	}
	else if (isEmpty(stack)) {
		newNode->next = NULL;
	}
	else {
		newNode->next = stack->top;
	}
	stack->top = newNode;
	stack->size++;
}
Element pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("stack is empty");
		exit(1);
	}
	Node* tmp = stack->top;
	int data = tmp->data;
	stack->top = stack->top->next;
	free(tmp);

	/*
	Node* tmp = stack->top;
	int data = tmp->data;
	free(stack->top);
	stack->top = tmp->next;
	*/

	return data;
}
Bool isFull(Stack* stack) {
	return stack->size == stack->capacity;
}
Bool isEmpty(Stack* stack) {
	return stack->size == 0;
}
void printStack(Stack* stack) {
	for (Node* tmp = stack->top; tmp != NULL; tmp = tmp->next) {
		printf("%d ", tmp->data);
	}
}
int main(void) {
	int capacity = 10;

	Stack* stack = createStack(capacity);
	
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	printStack(stack);
	printf("\n");
	printf("pop : %d\n", pop(stack));
	printStack(stack);

	return 0;
}
