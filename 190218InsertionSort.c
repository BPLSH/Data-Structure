#include <stdio.h>
#include <string.h>
void InsertionSort(int* ptr, int len) {
	int i, j, tmp;

	for (i = 1; i < len; i++) {
		if (ptr[i - 1] < ptr[i]) {
			continue;
		}
		tmp = ptr[i];
		for (j = 0; j < i; j++) {
			if (tmp < ptr[j]){
				memmove(ptr + j+1, ptr + j, (i - j) * sizeof(int));
				ptr[j] = tmp;
				break;
			}
		}
	}
}
int main(void) {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(int);
	int i;

	printf("before sort : ");
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("after sort : ");
	InsertionSort(arr, len);
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
