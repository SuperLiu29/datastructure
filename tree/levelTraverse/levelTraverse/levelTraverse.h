#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct treeNode
{
	char data;//������
	struct treeNode* lChild;
	struct treeNode* rChild;
}treeNode;
//ʹ��
typedef struct queueNode
{
	treeNode* data;//�������������
	struct queueNode* prev;
	struct queueNode* next;

}queueNode;
void createTree(treeNode** T, char* data, int* index);//������
void preOrder(treeNode* T);//�������
queueNode* initQueue();//��ʼ������
void enQueue(treeNode* data, queueNode* Q);//���
bool isQueueEmpty(queueNode* Q);//�ж϶����Ƿ�Ϊ��
queueNode* deQueue(queueNode* Q);//���Ӳ����ص�һ��Ԫ��
void levelTraverse(queueNode* Q, treeNode* T);//�������





