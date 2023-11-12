#include <stdio.h>
#include <stdlib.h>
#define Num 5
typedef struct hashList
{
	char* data;
	int num;
}hashList;
hashList* initHashList()
{
	hashList* list = (hashList*)malloc(sizeof(hashList));
	list->data = (char*)malloc(sizeof(char) * Num);
	//初始化
	for (int i = 0; i < Num; i++) {
		list->data[i] = 0;
	}
	list->num = 0;
	return list;
}
int hash(int data) {
	return data % Num;
}
void put(hashList* list, char data) {
	int index = hash(data);
	if (list->data[index] != 0) {
		//此时冲突
		//线性探测法
		int court = 1;
		while (list->data[index] != 0) {
			index = hash(hash(data) + court);
			court++;
		}
	}
	//此时解决冲突
	list->data[index] = data;
	list->num++;
}
void text() {
	hashList* list = initHashList();
	put(list, 'A');
	put(list, 'F');

	printf("%c ", list->data[0]);
	printf("%c ", list->data[1]);
}
int main() {
	text();
	return 0;
}