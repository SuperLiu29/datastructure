#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef struct queue
{
	int front;
	int tail;
	int* a;//����
	int k;//�洢Ԫ�ظ���
}queue;
queue* cycleQueueInit(int k);
void enQueue(queue* pq, int value);
bool isEmpty(queue* pq);
bool isFull(queue* pq);
void deQueue(queue* pq);
void printQueue(queue* pq);
int getRear(queue* pq);


