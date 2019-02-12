//stack 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Bool int
#define TRUE 1
#define FALSE 0
#define ElementType int
typedef struct tagNode{
	char* Data;
	struct tagNode* NextNode;
}Node;
typedef struct tagLinkedListStack {
	int Size;
	struct tagNode* List;
	struct tagNode* Top;
}LinkedListStack;
void LLS_CreateStack(LinkedListStack** Stack) {
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
	(*Stack)->Size = 0;
}
void LLS_DestroyStack(LinkedListStack* Stack) {//?
	free(Stack);
}
Node* LLS_CreateNode(char* Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(sizeof(strlen(Data) + 1));

	//NewNode->Data = Data;
	strcpy_s(NewNode->Data, strlen(Data)+1,Data); //sizeof(Data); //strlen;
	NewNode->NextNode = NULL;

	return NewNode;
}
void LLS_DestroyNode(Node* PopNode) { //주소를 담는건 다의심해봐라
	free(PopNode->Data);
	free(PopNode);
}
void LLS_Push(LinkedListStack* Stack, Node* TagNode) {
	if (LLS_IsEmpty(Stack)) {
		Stack->List = TagNode;
		Stack->Top = TagNode;
		Stack->Size++;
	}
	else {
		Stack->Top->NextNode = TagNode;
		Stack->Top = TagNode;
		Stack->Size++;
	}
}
Node* LLS_Pop(LinkedListStack* Stack) { //!
	Node* tmp = Stack->List;
	Node* top = Stack->Top;
	while (tmp->NextNode != top) {
		tmp = tmp->NextNode;
	}
	Stack->Top = tmp;
	Stack->Size--;

	return top;
}
Node* LLS_Top(LinkedListStack* Stack) {
	return Stack->Top;
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
	LLS_Push(Stack, LLS_CreateNode("hello0"));
	LLS_Push(Stack, LLS_CreateNode("hello1"));
	LLS_Push(Stack, LLS_CreateNode("hello2"));
	
	printf("%s", LLS_Top(Stack)->Data);
	printf("\n");
	printf("%s", LLS_Pop(Stack)->Data);
	LLS_DestroyNode(LLS_Pop(Stack));
}
