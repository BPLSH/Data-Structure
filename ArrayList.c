#include<stdio.h>
#include<stdlib.h>

typedef struct list { //구조체 설정하는거 물어봐야겠다.
	int *array;
	int size, capacity;
}List;

List * CreateList(int capacity);
void Add(List * list, int data);
int Remove(List * list);
//void Insert(List * list, int index, int data);
int RemoveAt(List * list, int index);
int isEmpty(List * list);
int isFull(List * list);
int size(List * list);

int main(void) { 
	int capacity = 10;
	List * alist = CreateList(capacity);
	Add(alist, 1); //주소보내서 이중포인터로 받는거랑 무슨 차이일까
	Add(alist, 2);
	
	return 0;
}
List * CreateList(int capacity) {
	List * list = (List *)malloc(sizeof(List)); //sizeof도 물어보자
	list->array = (int *)malloc(sizeof(capacity));
	list->capacity = capacity;
	list->size = 0;

	return list;
}
void Add(List * list, int data) {
	if (list->size >= list->capacity) {
		printf("데이터를 채울 공간이 없습니다.");
		return;
	}
	list->array[list->size] = data;
	printf("%d ", list->array[list->size]);
	
	list->size++;
}
int Remove(List * list) {

}
/**void Insert(List * list, int index, int data) {
	if (list->size >= list->capacity) {
		printf("데이터를 채울 공간이 없습니다.");
		return;
	}
	int tmp = list->array[index];
	list->array[index] = data;
	list->size++;
	for (int i = index + 1; i <= list->size; i++) {
		list->array[i] = tmp;
		tmp = list->array[i + 1];
	}
	printf("\n");
	printf("%d번째에 %d값을 넣은 후 : ", index + 1, data);

	for (int i = 0; i < list->size; i++) {
		printf("%d ", list->array[i]);
	}
}**/
int RemoveAt(List * list, int index) {

}
int isEmpty(List * list) {
	return list->size == 0;
}
int isFull(List * list) {
	return list->size == list->capacity;
}
int size(List * list) {
	return list->size;
}
