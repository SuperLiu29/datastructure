#include <stdio.h>
#include <stdlib.h>
//实现顺序表
typedef struct list {
	int* data;
	int length;
	int num;
}List;
List* initList(int length) {
	List* list = (List*)malloc(sizeof(list));
	list->data = (int*)malloc(sizeof(int) * length);
	list->length = length;
	list->num = 0;
	return list;
}
void listAdd(List* list, int data) {
	//插入数据
	//判断是否插满
	if (list->num == list->length) {
		return;
	}
	list->data[list->num] = data;
	list->num++;
}
void printList(List* list) {
	for (int i = 0; i < list->num; i++) {
		printf("%d ", list->data[i]);
	}
}
int  binarySearch(List* list, int key) {
	int start = 0;
	int end = list->num - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (key > list->data[mid]) {
			start = mid + 1;
		}
		else if (key < list->data[mid]) {
			end = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
int binarySearchRecursion(List* list, int key, int start, int end) {
	//递归实现二分查找

	//出口
	if (start == end) {
		if (list->data[start] == key) {
			return start;
		}
		else {
			return -1;
		}
	}
	int mid = (start + end) / 2;
	if (key > list->data[mid]) {
		//右查
		binarySearchRecursion(list, key, mid + 1, end);
	}
	else if (key < list->data[mid]) {
		//左查
		binarySearchRecursion(list, key, start, mid - 1);
	}
	else {
		return mid;
	}
}
void text() {
	List* list = initList(6);
	listAdd(list, 1);
	listAdd(list, 2);
	listAdd(list, 3);
	listAdd(list, 4);
	listAdd(list, 5);
	listAdd(list, 6);
	printList(list);
	printf("\n");
	printf("%d ", binarySearch(list, 2));
	printf("%d ", binarySearch(list, 6));
	printf("%d ", binarySearch(list, 0));
	printf("%d ", binarySearchRecursion(list, 5, 0, list->num - 1));
	printf("%d ", binarySearchRecursion(list, 4, 0, list->num - 1));
}
int main() {
	text();
}