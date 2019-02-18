#include <stdio.h>
#include <string.h>
void BubbleSort(int* ptr, int len) {
	int i, j, tmp;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (ptr[j] > ptr[j + 1]) {
				tmp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = tmp;
			}
		}
	}
}
int main(void) {
	int arr[] = { 5,2,7,9,1,8,3,10,4,6 };
	int len2 = sizeof(arr) / sizeof(int);
	int i;

	printf("before sort : ");
	for (i = 0; i < len2; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("after sort : ");
	BubbleSort(arr, len2);
	for (i = 0; i < len2; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
