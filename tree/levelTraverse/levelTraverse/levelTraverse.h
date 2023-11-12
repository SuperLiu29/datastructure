#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct treeNode
{
	char data;//数据域
	struct treeNode* lChild;
	struct treeNode* rChild;
}treeNode;
//使用
typedef struct queueNode
{
	treeNode* data;//队列里存放树结点
	struct queueNode* prev;
	struct queueNode* next;

}queueNode;
void createTree(treeNode** T, char* data, int* index);//创建树
void preOrder(treeNode* T);//先序遍历
queueNode* initQueue();//初始化队列
void enQueue(treeNode* data, queueNode* Q);//入队
bool isQueueEmpty(queueNode* Q);//判断队列是否为空
queueNode* deQueue(queueNode* Q);//出队并返回第一个元素
void levelTraverse(queueNode* Q, treeNode* T);//层序遍历





