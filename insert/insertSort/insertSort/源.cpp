#include <stdio.h>
#include <stdlib.h>
void insertSort(int* arr, int length) {
	//外循环-从第二个元素开始,与前面的元素比较并找到合适的位置进行插入
	for (int i = 1; i < length; i++) {
		//内循环-将该元素与前面的元素挨个比较[0,i-1]
		for (int j = 0; j <= i - 1; j++) {
			if (arr[i] < arr[j]) {
				//插入到j的前面
				//挪动元素
				int temp = arr[i];//先将该元素储存起来

				for (int k = i - 1; k >= j; k--) {
					arr[k + 1] = arr[k];//将j-i之间的元素后移
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