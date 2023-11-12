#include "stack.h"

void text()
{
	st st;
	initStack(&st);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	printf("%d ", getStackSize(&st));
	printf("\n");
	printf("%d ", stackTop(&st));
	printf("\n");
	stackPop(&st);
	stackPop(&st);
	stackPop(&st);
	stackPrint(&st);

}
int main()
{
	text();
}