#include <stdio.h>
#include <stdlib.h>
#define Bool int
#define TRUE 1
#define FALSE 0
typedef struct node {
	int data;
	struct node* next;
}Node;
typedef struct stack {
	struct node* top;
	int size;
}Stack;
Stack* createStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;

	return stack;
}
void push(Stack** stack, int data) {
	if (stack == NULL) {
		createStack();
	}
	
	if (isEmpty(&stack)) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;
		(*stack)->top = newNode;
		(*stack)->size++;

		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = (*stack)->top;
	(*stack)->top = newNode;
	(*stack)->size++;
}
void pop(Stack** stack) {
	if (isEmpty(&stack)) {
		printf("data is empty");
		exit(1);
	}
	Node* tmp = (*stack)->top->next;
	free((*stack)->top);
	(*stack)->top = tmp;
	(*stack)->size--;
}
Bool isEmpty(Stack** stack) {
	return (*stack)->size == 0;
}
int count(Stack** stack) {
	return (*stack)->size;
}
void printStack(Stack** stack) {
	Node* tmp = (*stack)->top;

	for (int i = 0; i < (*stack)->size; i++) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}
int main(void) {
	Stack* stack = createStack();
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);
	push(&stack, 50);
	pop(&stack);
	printStack(&stack);
}
