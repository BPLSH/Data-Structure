#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* previous;
	struct node* next;
}Node;
typedef struct list {
	struct node* head; //struct node head?
	struct node* tail;
	int size;
}List;

void initList(List** list); //List*
void add(List** list, int index, int data);
void addFirst(List** list, int data);
void addLast(List** list, int data);
//Node* removeNode(List** list, int index);
//Node* removeFirstNode(List** list);
//Node* removeLastNode(List** list);
//void removeAll(List** list);
int size(List** list);
void printAll(List** list);
void println();
int main(void) {
	List* list;  //받는거
	initList(&list);
	add(&list, 1,10);
	add(&list, 2,20);

	//printAll(&list);
	printf("노드의 개수: %d", size(&list));
	return 0;
}
void initList(List** list) {
	(*list) = (List*)malloc(sizeof(List));
	(*list)->head = NULL; //이것도 모르겠다 List** List* 이게 너무 헷갈린다.
	(*list)->tail = NULL;
	(*list)->size = 0;
}
void add(List** list, int index, int data) {
	if (!(*list)) {
		printf("리스트가 비었습니다.");
		return;
	}
	if (index == 1 && (*list)->size == 0) { //맨처음생성
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->previous = NULL;
		newNode->next = NULL;
		(*list)->head = newNode;
		(*list)->tail = newNode;
	}
	else if (index == 1) { //인덱스가 1일경우 노드생성
		addFirst((*list), data);
	}
	
	else if(index == ((*list)->size)+1){ //맨끝에 노드생성
		addLast((*list), data);
	}
	else /*(index > 0 && index <= (*list)->size)*/{  //중간에 생성
		Node* newNode = (Node*)malloc(sizeof(Node));
		Node* tmp = (*list)->head;
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		newNode->data = data;
		newNode->previous = tmp->previous;
		newNode->next = tmp;
	}
	(*list)->size++;
}
void addFirst(List** list, int data) { //맨 앞에 노드생성
	if ((*list)->head == NULL) {
		add(list, 1,data);
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->previous = NULL;
	newNode->next = (*list)->head;
	
	(*list)->head->previous = newNode;
	(*list)->head = newNode;
	(*list)->size++;
}
void addLast(List** list, int data) { //맨 뒤에 노드생성
	if ((*list)->head == NULL) {
		add(list, 1, data);
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	(*list)->tail->next = newNode;
	newNode->data = data;
	newNode->previous = (*list)->tail;
	newNode->next = NULL;
	(*list)->tail = newNode;
	(*list)->size++;
}
Node* removeNode(List** list, int index) { //index? data?
	if ((*list)->head == NULL) {
		exit(1);
	}
	if ((*list)->size < index) {
		printf("index를 확인해주세요");
		exit(1);//return;가능?
	}
	Node* del = (*list)->head;
	for (int i = 0; i < index - 1; i++) {
		del = del->next;
	}
	(*list)->size--;
	return del;
}
Node* removeFirstNode(List** list) {
	if ((*list)->head == NULL) {
		exit(1);
	}
	Node* del = (*list)->head;
	(*list)->head = (*list)->head->next;
	(*list)->size--;
	return del;
}
Node* removeLastNode(List** list) {
	if ((*list)->head == NULL) {
		exit(1);
	}
	Node* del = (*list)->tail;
	(*list)->tail = (*list)->tail->previous;
	(*list)->size--;
	return del;
}
void removeAll(List** list) {
	if ((*list)->head == NULL) {
		exit(1);
	}
	for (Node* current = (*list)->head; current != NULL; current = current->next) {
		free(current); //이게 성공적으로 작동했다면 표현합니다.
		(*list)->size--;
	}
}
int size(List** list) {
	return (*list)->size;
}
void printAll(List** list) {
	if ((*list)->size == 0) { //리스트가 빈 경우
		printf("리스트가 비었습니다.");
		return;
	}
	if (!(*list)) { //리스트가 널인 경우 //같이 해도 되나?
		printf("리스트를 만들어주세요.");
		return;
	}
	for (Node* current = (*list)->head; current != NULL; current = current->next)
		printf("%d ", current->data);
	println();
	/*Node* current = (*list)->head;
	for (int i = 0;i <(*list)->size;i++) {
		printf("%d ", current->data);
		current = current->next;
	}*/
}
void println() {
	printf("\n");
}
