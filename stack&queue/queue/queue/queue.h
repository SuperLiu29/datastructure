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
typedef struct queue //为什么定义成结构体?-因为有头尾两个指针起作用,如果不定义成一个结构体,实现部分接口就需要传更多的参数
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

