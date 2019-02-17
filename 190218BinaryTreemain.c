#include "BinaryTree.h"

int main(void) {
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');

	SBT_AddChild(A, B);
	SBT_AddChild(A, E);
	SBT_AddChild(B, C);
	SBT_AddChild(B, D);
	SBT_AddChild(E, F);
	SBT_AddChild(E, G);

	printf("PreOrder...\n");
	SBT_PreorderPrintTree(A);
	printf("\n");
	printf("InOrder...\n");
	SBT_InorderPrintTree(A);
	printf("\n");
	printf("PostOrder...\n");
	SBT_PostorderPrintTree(A);
	printf("\n");
	return 0;
}
