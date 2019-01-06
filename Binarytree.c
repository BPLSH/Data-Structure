#include<stdio.h>
#include<stdlib.h>
typedef struct BinaryNode {
	int data;
	struct BinaryNode * leftChild;
	struct BinaryNode * rightChild;
}BinNode;
typedef struct BinaryTree {
	struct BinaryNode * rootNode;
}BinTree;
BinNode * curParent; //기준이 문제가 됨
void InitBinTree(BinTree * pBintree, int data) {
	BinTree * pBintree = (BinTree *)malloc(sizeof(BinTree));
	if (pBintree->rootNode == NULL) { //처음 루트노드 생성
		pBintree->rootNode->data = data;
		pBintree->rootNode->leftChild = NULL;
		pBintree->rootNode->rightChild = NULL;
		curParent = pBintree->rootNode;
	}

}
void addLeftChildNode(BinTree * pBintree, int data) {
	BinNode *pLeftChild = (BinNode *)malloc(sizeof(BinNode));
	curParent->leftChild= pLeftChild;
	pLeftChild->data = data;
	pLeftChild->leftChild = NULL;
	pLeftChild->rightChild = NULL;
	curParent = pLeftChild;
}
void addRightChildNode(BinTree * pBintree, int data) {
	BinNode *pRightChild = (BinNode *)malloc(sizeof(BinNode));
	curParent->rightChild = pRightChild;
	pRightChild->data = data;
	pRightChild->leftChild = NULL;
	pRightChild->rightChild = NULL;
	curParent = pRightChild;
}
int main(void) {
	BinTree pBintree;
	InitBintTree(&pBintree);
	addLeftChildNode(&pBintree,10);
	return 0;
}
