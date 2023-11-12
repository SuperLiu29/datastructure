#include <stdio.h>
#include <stdlib.h>
void shellSort(int* arr, int length, int step) {
	for (int i = 0; i < length; i++) {
		//外层循环从第一个元素开始分组
		for (int j = i + step; j < length; j += step) {
			//内层1循环将i+step的元素都分到一起
			for (int k = i; k < j; k += step) {
				//内层2循环将分好的组内元素进行插入排序
				if (arr[k] > arr[j]) {
					int temp = arr[j];
					for (int l = j - step; l >= k; l -= step) {
						//此for循环用于挪动j-k间的元素
						//l之所以从j-step开始,因为需要从j前一个元素开始依次往后挪动,最后剩下k索引为空用于置放j之前的索引值
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
		//每排序一次输出一次
		printArray(arr, length);
	}
	return 0;
}