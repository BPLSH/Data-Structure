#include<stdio.h>
#include<stdlib.h>
#define Left 0
#define Right 1
typedef struct node {
	int data;
	struct node* leftchild;
	struct node* rightchild;
}Node;
Node* root;
void initRootNode(int data) {
	root = (Node*)malloc(sizeof(Node));
	root->data = data;
	root->leftchild = NULL;
	root->rightchild = NULL;
}
Node* createNode(Node* parent, int child, int data) {
	/*if ((*parent) == NULL) {
		printf("부모를 확인해주세요");
		return;
	}*/
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->leftchild = NULL;
	newNode->rightchild = NULL;
	if (child == Left) {
		parent->leftchild = newNode;
	}
	if (child == Right) {
		parent->rightchild = newNode;
	}
	return newNode;
	
}
void preorder(Node* root) { //전위
	printf("%d ", root->data);
	if (root->leftchild) {
		preorder(root->leftchild);
	}
	if (root->rightchild) {
		preorder(root->rightchild);
	}
	printfln();
}
void inorder(Node* root) { //중위
	
	if (root->leftchild) {
		inorder(root->leftchild);
	}
	printf("%d ", root->data);
	if (root->rightchild) {
		inorder(root->rightchild);
	}
	printfln();
}
void postorder(Node* root) { //후위
	
	if (root->leftchild) {
		postorder(root->leftchild);
	}
	if (root->rightchild) {
		postorder(root->rightchild);
	}
	printf("%d ", root->data);
	printfln();
}
void printfln() {
	printf("\n");
}
int main(void) {
	initRootNode(1);
	createNode(root, Left, 2);
	createNode(root, Right, 3);
	inorder(root);
	//동적할당이면 여기서 접근가능?

}
