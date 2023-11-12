#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int weight;
	int parent;
	int lchild;
	int rchild;
}treeNode;
typedef struct huffmanTree {
	treeNode* data;
	int length;
}hfTree;
hfTree* hfTreeInit(int* weight, int length) {
	hfTree* T = (hfTree*)malloc(sizeof(hfTree));
	T->data = (treeNode*)malloc(sizeof(treeNode) * (2 * length - 1));//��n������γɵĹ���������2n-1�����
	T->length = length;
	for (int i = 0; i < length; i++) {
		T->data[i].weight = weight[i];
		//-1����û�к���
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
		T->data[i].parent = 0;
	}
	return T;
}
int* selectMin(hfTree* T) {
	int min = 10000;
	int secondMin = 10000;
	int minIndex = 0;
	int secondIndex = 0;
	for (int i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0) {
			if (T->data[i].weight < min) {
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	for (int i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0 && i != minIndex) {
			if (T->data[i].weight < secondMin) {
				secondMin = T->data[i].weight;
				secondIndex = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);//��������

	res[0] = minIndex;
	res[1] = secondIndex;
	return res;
}
void creatHuffmanTree(hfTree* T) {
	int length = T->length * 2 - 1;//�߽�
	int* res;
	int min = -1;
	int secondMin = -1;
	for (int i = T->length; i < length; i++) {
		//��Ϊ�������Ѿ�����˳�ʼ��T->length��ֵ,�����±��T->length��ʼ
		res = selectMin(T);
		//�������
		min = res[0];
		secondMin = res[1];
		T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
		T->data[i].parent = 0;
		T->data[min].parent = i;
		T->data[secondMin].parent = i;
		T->data[i].lchild = min;
		T->data[i].rchild = secondMin;
		T->length++;
	}
}
void preOrder(hfTree* T, int index) {
	if (index != -1) {
		//��Ϊ����㶼������һ��������,����ͨ���±����,
		printf("%d ", T->data[index].weight);
		preOrder(T, T->data[index].lchild);
		preOrder(T, T->data[index].rchild);
	}
}
int main() {
	int weight[5] = { 1,2,3,4,5 };
	hfTree* T = hfTreeInit(weight, 5);
	creatHuffmanTree(T);
	preOrder(T, T->length - 1);
	return 0;
}