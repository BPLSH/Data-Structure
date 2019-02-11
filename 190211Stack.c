//stack
#include <stdio.h>
#include <stdlib.h>
#define Bool int
#define TRUE 1
#define FALSE 0
#define ElementType int
typedef struct tagNode {
	ElementType Data;
}Node;
typedef struct tagArrayStack {
	int Capacity;
	int Top;
	int Size;
	Node* Nodes;
}ArrayStack;
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = Capacity-1;
	(*Stack)->Size = 0;
}
void AS_DestroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);
	free(Stack);
}
void AS_Push(ArrayStack* Stack, int Data) {
	Stack->Top = (Stack->Top+1) % Stack->Capacity;
	int Position = Stack->Top;
	Stack->Nodes[Position].Data = Data; //->, .
	Stack->Size++;
}
ElementType AS_Pop(ArrayStack* Stack) {
	int Position = Stack->Top;
	
	Stack->Top--;
	Stack->Size--;

	return Stack->Nodes[Position].Data;
}
ElementType AS_Top(ArrayStack* Stack) {
	int Position = Stack->Top;

	return Stack->Nodes[Position].Data;
}
int AS_GetSize(ArrayStack* Stack) {
	return Stack->Size;
	Stack->Size = Stack->Top + 1;
}
int AS_IsEmpty(ArrayStack* Stack) {
	return Stack->Size == 0;
}
int main(void) {
	int i = 0;
	int Capacity = 10;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 10);
	
	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);
	printf("%d ", AS_Top(Stack));
	AS_Pop(Stack);
	printf("%d ", AS_Top(Stack));
	printf("%d ", AS_GetSize(Stack));
	return 0;
}
