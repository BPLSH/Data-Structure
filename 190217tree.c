#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType Data) {
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->Data = Data;
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;

	return NewNode;
}
void LCRS_DestroyNode(LCRSNode* NewNode) {
	free(NewNode);
}
void LCRS_DestroyTree(LCRSNode* Root) {
	LCRSNode* tmp = Root;
	if (tmp->LeftChild != NULL) {
		LCRS_DestroyTree(tmp->LeftChild);
	}
	if (tmp->RightSibling != NULL) {
		LCRS_DestroyTree(tmp->RightSibling);
	}
	LCRS_DestroyNode(tmp);
}
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child) {
	if (Parent->LeftChild == NULL) {
		Parent->LeftChild = Child;
	}
	else {
		LCRSNode* tmp = Parent->LeftChild;
		while (tmp->RightSibling != NULL) {
			tmp = tmp->RightSibling;
		}
		tmp->RightSibling = Child;
	}
}
void LCRS_PrintTree(LCRSNode* Node, int Depth) {
	int i;

	for (i = 0; i < Depth; i++) {
		printf(" ");
	}
	printf("%c\n", Node->Data);

	if (Node->RightSibling != NULL) {
		LCRS_PrintTree(Node->RightSibling, Depth);
	}
	if (Node->LeftChild != NULL) {
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	}
}
