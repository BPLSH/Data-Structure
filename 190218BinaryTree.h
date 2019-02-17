#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

typedef char ElementType;
typedef struct tagSBTNode {
	struct SBTNode* LeftChild;
	struct SBTNode* RightChild;
	ElementType Data;
}SBTNode;
SBTNode* SBT_CreateNode(ElementType Data);
void SBT_AddChild(SBTNode* Parent, SBTNode* Child);
void SBT_DsetroyNode(SBTNode* Node);
void SBT_DestroyTree(SBTNode* Root);
void SBT_PreorderPrintTree(SBTNode* Root);
void SBT_InorderPrintTree(SBTNode* Root);
void SBT_PostorderPrintTree(SBTNode* Root);
#endif BINARYTREE_H
