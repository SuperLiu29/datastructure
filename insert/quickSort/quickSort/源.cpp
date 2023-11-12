#include <stdio.h>
#include <stdlib.h>
int partition(int* arr, int i, int j) {
	int x = arr[i];
	while (i < j) {
		//�Ӻ���ǰ
		while (i < j && x <= arr[j]) {
			j--;
		}
		if (i < j) {
			//��ʱ�ҵ���λ���ұ�������ֵС����Ŧ����
		//����ߵĿ�λ�
			arr[i] = arr[j];
			i++;
		}
		//��ʱ��ǰ����
		while (i < j && x > arr[i]) {
			i++;
		}
		if (i < j) {
			//��ʱ�ҵ���λ�����������ֵС����Ŧ����
		//���ұߵĿ�λ�
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
		//�������ӱ�
		quickSort(arr, i, index - 1);
		//�������ӱ�
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