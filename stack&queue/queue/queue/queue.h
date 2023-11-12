#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef int  dataType;
typedef struct queueNode
{
	struct queueNode* next;
	dataType data;
}qNode;
typedef struct queue //Ϊʲô����ɽṹ��?-��Ϊ��ͷβ����ָ��������,����������һ���ṹ��,ʵ�ֲ��ֽӿھ���Ҫ������Ĳ���
{
	qNode* head;
	qNode* tail;

}queue;
void queueInit(queue* pq);
void queueDestory(queue* pq);
void queuePush(queue* pq,dataType x);
void queuePop(queue* pq);
dataType queueFront(queue* pq);
dataType queueBack(queue* pq);
int queueSize(queue* pq);
bool isQueueEmpty(queue* pq);

