#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType Data) {
	SBTNode* Node = (SBTNode*)malloc(sizeof(SBTNode));
	Node->LeftChild = NULL;
	Node->RightChild = NULL;
	Node->Data = Data;

	return Node;
}
void SBT_AddChild(SBTNode* Parent, SBTNode* Child) {
	if (Parent->LeftChild != NULL && Parent->RightChild != NULL) {
		return;
	}
	if (Parent->LeftChild == NULL) {
		Parent->LeftChild = Child;
	}
	else {
		Parent->RightChild = Child;
	}
}
void SBT_DsetroyNode(SBTNode* Node) {
	free(Node);
}
void SBT_DestroyTree(SBTNode* Root){
}
void SBT_PreorderPrintTree(SBTNode* Root){
	SBTNode* tmp = Root;
	printf("%c ", tmp->Data);

	if (tmp->LeftChild != NULL) {
		SBT_PreorderPrintTree(tmp->LeftChild);
	}
	if (tmp->RightChild != NULL) {
		SBT_PreorderPrintTree(tmp->RightChild);
	}
}
void SBT_InorderPrintTree(SBTNode* Root){
	SBTNode* tmp = Root;
	if (tmp->LeftChild != NULL) {
		SBT_InorderPrintTree(tmp->LeftChild);
	}
	printf("%c ", tmp->Data);
	if (tmp->RightChild != NULL) {
		SBT_InorderPrintTree(tmp->RightChild);
	}
}
void SBT_PostorderPrintTree(SBTNode* Root) {
	SBTNode* tmp = Root;
	if (tmp->LeftChild != NULL) {
		SBT_PostorderPrintTree(tmp->LeftChild);
	}
	if (tmp->RightChild != NULL) {
		SBT_PostorderPrintTree(tmp->RightChild);
	}
	printf("%c ", tmp->Data);

}
