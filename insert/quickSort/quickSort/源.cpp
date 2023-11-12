#include <stdio.h>
#include <stdlib.h>
int partition(int* arr, int i, int j) {
	int x = arr[i];
	while (i < j) {
		//从后往前
		while (i < j && x <= arr[j]) {
			j--;
		}
		if (i < j) {
			//此时找到了位于右边区域且值小于枢纽的数
		//将左边的空位填补
			arr[i] = arr[j];
			i++;
		}
		//此时从前往后
		while (i < j && x > arr[i]) {
			i++;
		}
		if (i < j) {
			//此时找到了位于左边区域且值小于枢纽的数
		//将右边的空位填补
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = x;
	return i;
}
void quickSort(int* arr, int i, int j) {
	if (i < j) {
		int index = partition(arr, i, j);
		//快排左子表
		quickSort(arr, i, index - 1);
		//快排右子表
		quickSort(arr, index + 1, j);
	}
}
void printfArray(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[8] = { 27, 38, 13, 49, 76, 97, 65, 49 };
	quickSort(arr, 0, 7);
	printfArray(arr, 8);
	return 0;
}