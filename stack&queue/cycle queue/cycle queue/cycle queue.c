#include "cycle.h"
queue* cycleQueueInit(int k)
{
	//���һ������ָ��
	//���ٿռ�
	queue* pq = (queue*)malloc(sizeof(queue));
	//Ϊ���鿪�ٿռ�
	pq->a = (int*)malloc(sizeof(int)*(k+1));//��Ҫ�࿪��һ���ռ����ж϶����Ƿ����
	pq->k = k;//����
	pq->front = pq->tail = 0;
	return pq;

}
void enQueue(queue* pq,int value)
{
	//���ж��Ƿ����
	assert(!isFull(pq));
	//���Ԫ��
	//β��
	pq->a[pq->tail] = value;
	pq->tail++;
	pq->tail %= ((pq->k) + 1);//�����±�Խ��
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
	pq->front %= ((pq->k) + 1);//�����±�Խ��
}
void printQueue(queue* pq)
{
	int length = (pq->tail - pq->front + pq->k+1) % (pq->k+1);//��ȡ����ʱ������Ԫ�صĸ���
	printf("%d", length);
	printf("\n");
	int index = pq->front;
	for (int i = 0; i < length; i++)
	{
		printf("%d->", pq->a[i]);
		index = (index + 1) % (pq->k + 1);//index����Խ��
	}
}
int getRear(queue* pq)
{
	assert(!isEmpty(pq));
	int i = (pq->tail + pq->k) % (pq->k + 1);//���tailΪ0���,�����һ��Ԫ���±�Ϊk-1ʱ
	return pq->a[i];
}

