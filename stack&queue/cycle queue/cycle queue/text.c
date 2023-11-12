#include "cycle.h"

int main()
{
	queue*pq=cycleQueueInit(5);
	enQueue(pq, 1);
	enQueue(pq, 2);
	enQueue(pq, 3);
	enQueue(pq, 4);
 	printQueue(pq);
	return 0;
}