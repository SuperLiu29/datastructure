#include "stack.h"
void initStack(st* pst)//初始化栈
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
void stackPush(st* pst, dataType x)//插入元素
{
	assert(pst);
	//需要判断空间是否足够
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		st* tmp = realloc(pst->a, sizeof(st) * newcapacity);//将原数组空间扩容
		pst->a = tmp;
		pst->a[pst->top] = x;
		
		if (tmp == NULL)//扩容失败
		{
			printf("realloc fail");
			exit(-1);
		}
		pst->capacity = newcapacity;
		pst->top++;
	}
	else
	{
		pst->a[pst->top] = x;
		pst->top++;

	}
}
void stackDestroy(st* pst)//摧毁栈
{
	assert(pst);
	free(pst->a);
}
bool isStackEmpty(st* pst)//判断栈区是否为空
{
	return pst->top == 0;//为0返回TRUE否则返回FALSE
}
void stackPop(st* pst)//删除栈顶元素
{
	//需要考虑是否删完
	assert(pst);
	assert(!isStackEmpty(pst));
	pst->top--;
}
int getStackSize(st* pst)//获取栈区元素个数
{
	assert(pst);
	return pst->top;
}
dataType stackTop(st* pst)//获取栈顶元素
{
	assert(pst);
	assert(!isStackEmpty(pst));
	return pst->a[pst->top-1];
}
void stackPrint(st* pst)
{
	while (!isStackEmpty(pst))
	{
		printf("%d ", stackTop(pst));
		pst->top--;
	}
	stackDestroy(pst);
}
