#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int* arr, int length) {
	for (int i = 0; i < length - 1; i++) {
		//��Ϊÿ���ҵ�һ����ֵ,����ֻ��Ҫִ��length-1��
		for (int j = 0; j < length - i - 1; j++) {
			//��Ϊÿ�ζ����ҵ�һ��,����j<length-1-i
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void printArray(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[10] = { 49,38,65,97,76,13,27,49,55,4 };
	int length = 10;
	bubbleSort(arr, 10);
	printArray(arr, 10);

	return 0;
}