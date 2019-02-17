#ifndef LCRSTREE_H
#define LCRSTREE_H

#include<stdio.h>
#include<stdlib.h>

typedef char ElementType;
typedef struct tagLCRSNode {
	ElementType Data;

	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;
}LCRSNode;

LCRSNode* LCRS_CreateNode(ElementType Data);
void LCRS_DestroyNode(LCRSNode* NewNode);
void LCRS_DestroyTree(LCRSNode* Root);
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child);
void LCRS_PrintTree(LCRSNode* Node, int Depth);
#endif
