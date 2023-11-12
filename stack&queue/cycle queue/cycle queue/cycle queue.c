#include "cycle.h"
queue* cycleQueueInit(int k)
{
	//获得一个队列指针
	//开辟空间
	queue* pq = (queue*)malloc(sizeof(queue));
	//为数组开辟空间
	pq->a = (int*)malloc(sizeof(int)*(k+1));//需要多开辟一个空间来判断队列是否存满
	pq->k = k;//长度
	pq->front = pq->tail = 0;
	return pq;

}
void enQueue(queue* pq,int value)
{
	//先判断是否存满
	assert(!isFull(pq));
	//添加元素
	//尾插
	pq->a[pq->tail] = value;
	pq->tail++;
	pq->tail %= ((pq->k) + 1);//避免下标越界
}
bool isEmpty(queue* pq)
{
	return pq->front == pq->tail;
}
bool isFull(queue* pq)
{
	return ((pq->tail + 1) % pq->k) == pq->front;
}
void deQueue(queue* pq)
{
	assert(!isEmpty(pq));
	pq->front++;
	pq->front %= ((pq->k) + 1);//避免下标越界
}
void printQueue(queue* pq)
{
	int length = (pq->tail - pq->front + pq->k+1) % (pq->k+1);//获取到此时队列中元素的个数
	printf("%d", length);
	printf("\n");
	int index = pq->front;
	for (int i = 0; i < length; i++)
	{
		printf("%d->", pq->a[i]);
		index = (index + 1) % (pq->k + 1);//index可能越界
	}
}
int getRear(queue* pq)
{
	assert(!isEmpty(pq));
	int i = (pq->tail + pq->k) % (pq->k + 1);//如果tail为0情况,即最后一个元素下标为k-1时
	return pq->a[i];
}

