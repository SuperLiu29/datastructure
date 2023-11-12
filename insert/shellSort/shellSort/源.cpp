#include <stdio.h>
#include <stdlib.h>
void shellSort(int* arr, int length, int step) {
	for (int i = 0; i < length; i++) {
		//���ѭ���ӵ�һ��Ԫ�ؿ�ʼ����
		for (int j = i + step; j < length; j += step) {
			//�ڲ�1ѭ����i+step��Ԫ�ض��ֵ�һ��
			for (int k = i; k < j; k += step) {
				//�ڲ�2ѭ�����ֺõ�����Ԫ�ؽ��в�������
				if (arr[k] > arr[j]) {
					int temp = arr[j];
					for (int l = j - step; l >= k; l -= step) {
						//��forѭ������Ų��j-k���Ԫ��
						//l֮���Դ�j-step��ʼ,��Ϊ��Ҫ��jǰһ��Ԫ�ؿ�ʼ��������Ų��,���ʣ��k����Ϊ�������÷�j֮ǰ������ֵ
						arr[l + step] = arr[l];
					}
					arr[k] = temp;
				}
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
	int arr[10] = { 49, 38, 65, 97, 76, 13, 27, 49, 55, 4 };
	int step[3] = { 5,3,1 };
	int length = 10;
	for (int i = 0; i < 3; i++) {
		shellSort(arr, length, step[i]);
		//ÿ����һ�����һ��
		printArray(arr, length);
	}
	return 0;
}