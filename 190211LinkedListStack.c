//stack
#include <stdio.h>
#include <stdlib.h>
#define Bool int
#define TRUE 1
#define FALSE 0
#define ElementType int
typedef struct tagNode {
	char* Data;
	struct tagNode* Next;
}Node;
typedef struct tagLinkedListStack {
	int Size;
	struct tagNode* Top;
	struct tagNode* List;
}LinkedListStack;
void LLS_CreateStack(LinkedListStack** Stack) {
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->Size = 0;
	(*Stack)->Top = NULL;
	(*Stack)->List = NULL;
}
void LLS_DestroyStack(LinkedListStack* Stack) {
	
	free(Stack);
}
void LLS_Push(LinkedListStack* Stack, char** Data) {
	if (LLS_IsEmpty(Stack)) {
		Node* NewNode = (Node*)malloc(sizeof(Node));
		NewNode->Data = (*Data);
		NewNode->Next = NULL;
		(Stack)->Top = NewNode;
		(Stack)->List = NewNode;
	}
	else {
		Node* NewNode = (Node*)malloc(sizeof(Node));
		NewNode->Data = (*Data);
		(Stack)->List->Next = NewNode;
		(Stack)->List = NewNode;
	}
}
char* LLS_Pop(LinkedListStack* Stack) {
	char* rt_Data = Stack->List->Data;
	
	Node* tmp = Stack->Top;
	while (tmp->Next != NULL) {
		tmp = tmp->Next;
	}
	Stack->List = tmp;
	free(tmp->Next);
	Stack->Size--;
	
	return rt_Data;
}
char* LLS_Top(LinkedListStack* Stack) {
	return Stack->List->Data;
}
int LLS_GetSize(LinkedListStack* Stack) {
	return Stack->Size;
}
int LLS_IsEmpty(LinkedListStack* Stack) {
	return Stack->Size == 0;
}
int main(void) {
	LinkedListStack* Stack = NULL;
	LLS_CreateStack(&Stack);
}
