#include <stdio.h>
#include <stdlib.h>
void insertSort(int* arr, int length) {
	//��ѭ��-�ӵڶ���Ԫ�ؿ�ʼ,��ǰ���Ԫ�رȽϲ��ҵ����ʵ�λ�ý��в���
	for (int i = 1; i < length; i++) {
		//��ѭ��-����Ԫ����ǰ���Ԫ�ذ����Ƚ�[0,i-1]
		for (int j = 0; j <= i - 1; j++) {
			if (arr[i] < arr[j]) {
				//���뵽j��ǰ��
				//Ų��Ԫ��
				int temp = arr[i];//�Ƚ���Ԫ�ش�������

				for (int k = i - 1; k >= j; k--) {
					arr[k + 1] = arr[k];//��j-i֮���Ԫ�غ���
				}
				arr[j] = temp;
			}
		}
	}
}
void text() {
	int arr[6] = { 4,3,5,9,6,2 };
	insertSort(arr, 6);
	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
}
int main() {
	text();
	return 0;
}