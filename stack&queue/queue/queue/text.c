#include "queue.h"
void textQueue()
{
	queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	printf("%d", queueFront(&q));
	printf("%d", queueBack(&q));
	printf("%d", queueSize(&q));
	queuePop(&q);
	queuePop(&q);
	queuePop(&q);
	queuePop(&q);
	printf("%d", queueFront(&q));
}
void text2()
{
}
int main()
{
	textQueue();
}