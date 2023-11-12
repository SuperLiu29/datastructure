#pragma once
#include "queue.h"
void queueInit(queue* pq)//��ʼ��
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void queueDestory(queue* pq)//�ݻ�
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
	//�������½��
	qNode* newNode = (qNode*)malloc(sizeof(qNode));
	newNode->data = x;
	if (pq->head == NULL)
	{
		//˵����ʱ������Ԫ��
		pq->tail = pq->head = newNode;
	}
	else
	{
		//��Ϊֻ�ܴ�β��
		if (!isQueueEmpty(pq)) {
			pq->tail->next = newNode;//�迼�Ƕ����Ƿ�Ϊ�գ���ΪNULL��ָ���κοռ�
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
	//ֻ��ͷɾ
	qNode* next = pq->head->next;//������һ���ڵ�,��ָ��ɾ
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