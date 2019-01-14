#include<stdio.h>
#include <stdlib.h>
#define capacity maxStackSize
#define Bool int
typedef struct node {
	int data;
	struct node* next;
}Node;
typedef struct stack {
	struct node* top;
	int capacity;
	int size; //size를 안쓰고는 못할까?
}Stack;
Stack* CreateStack(int capacity); //stack으로 리턴하면 안되는 이유
Node* Push(Stack * stack, int data); //반환자료형을 여러가지로 해보고싶다
//Node* Pop(Stack * stack);
//Bool IsFull(Stack * stack, int capacity);
Bool IsEmpty(Stack * stack);
int main(void) {
	int capacity = 10;
	Stack * stack = CreateStack(capacity);
	printf("%d ", Push(stack, 10)->data);
	printf("%d ", Push(stack, 20)->data);
	printf("%d ", Push(stack, 30)->data);
	printf("%d ", Push(stack, 40)->data);
	printf("%d ", Push(stack, 60)->data);
	printf("%d ", Push(stack, 70)->data);
	printf("%d ", Push(stack, 80)->data);
	printf("%d ", Push(stack, 90)->data);
	printf("%d ", Push(stack, 100)->data);
	printf("%d ", Push(stack, 110)->data);
	Stack * stack2 = (Stack *)malloc(sizeof(Stack));
	printf("%d", _msize(stack2));
	//printf("%d ", stack[0]->data); //이문장 왜안될까?
	return 0;
}
Stack* CreateStack(int capacity) { //stack으로 리턴하면 안되는 이유
	Stack * stack = (Stack *)calloc(capacity, sizeof(Node)); //node * head 에도 0이 들어가나요?
	stack->top = NULL;
	stack->capacity = capacity;
	stack->size = 0;

	return stack;
}
Node* Push(Stack * stack, int data) {
	if (stack->size >= stack->capacity) {
		printf("stack의 용량이 %d로 꽉 찼습니다.", stack->capacity); //이럴때 retrun 하는건가
		
		exit(1); //return이 작동을 안한다.
	}
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	//if (IsEmpty(stack)) {
		//stack->top = newNode; //return 언제쓴다고했지
	//}
	
	newNode->next = stack->top; //맨처음일때 이래도 되나?
	stack->top = newNode;
	stack->size++;

	return newNode;
}
Node* Pop(Stack * stack) {
	
}
Bool IsFull(Stack * stack, int capacity) {
	return stack->size == stack->capacity; //capacity하면 안된다.
}
Bool IsEmpty(Stack * stack) {
	return stack->top == NULL;
}
