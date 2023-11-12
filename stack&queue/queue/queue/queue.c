#pragma once
#include "queue.h"
void queueInit(queue* pq)//初始化
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void queueDestory(queue* pq)//摧毁
{
	assert(pq);
	qNode* cur = pq->head;
	while (cur)
	{
		qNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void queuePush(queue* pq, dataType x)
{
	assert(pq);
	//先生成新结点
	qNode* newNode = (qNode*)malloc(sizeof(qNode));
	newNode->data = x;
	if (pq->head == NULL)
	{
		//说明此时队列无元素
		pq->tail = pq->head = newNode;
	}
	else
	{
		//因为只能从尾插
		if (!isQueueEmpty(pq)) {
			pq->tail->next = newNode;//需考虑队列是否为空，因为NULL不指向任何空间
			newNode->next = NULL;
			pq->tail = newNode;
		}
		else {
			return;
		}
	}
}
void queuePop(queue* pq)
{
	assert(pq);
	assert(!isQueueEmpty(pq));
	//只能头删
	qNode* next = pq->head->next;//储存下一个节点,先指后删
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}
dataType queueFront(queue* pq)
{
	assert(pq);
	assert(!isQueueEmpty(pq));
	return pq->head->data;
}
dataType queueBack(queue* pq)
{
	assert(pq);
	assert(!isQueueEmpty(pq));
	return pq->tail->data;
}
int queueSize(queue* pq)
{
	int count = 0;
	qNode* cur = pq->head;
	while (cur)
	{
		qNode* next = cur->next;
		count++;
		cur = next;
	}
	return count;
}
bool isQueueEmpty(queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}