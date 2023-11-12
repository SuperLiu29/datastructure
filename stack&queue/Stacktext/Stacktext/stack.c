#include "stack.h"
void initStack(st* pst)//��ʼ��ջ
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
void stackPush(st* pst, dataType x)//����Ԫ��
{
	assert(pst);
	//��Ҫ�жϿռ��Ƿ��㹻
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		st* tmp = realloc(pst->a, sizeof(st) * newcapacity);//��ԭ����ռ�����
		pst->a = tmp;
		pst->a[pst->top] = x;
		
		if (tmp == NULL)//����ʧ��
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
void stackDestroy(st* pst)//�ݻ�ջ
{
	assert(pst);
	free(pst->a);
}
bool isStackEmpty(st* pst)//�ж�ջ���Ƿ�Ϊ��
{
	return pst->top == 0;//Ϊ0����TRUE���򷵻�FALSE
}
void stackPop(st* pst)//ɾ��ջ��Ԫ��
{
	//��Ҫ�����Ƿ�ɾ��
	assert(pst);
	assert(!isStackEmpty(pst));
	pst->top--;
}
int getStackSize(st* pst)//��ȡջ��Ԫ�ظ���
{
	assert(pst);
	return pst->top;
}
dataType stackTop(st* pst)//��ȡջ��Ԫ��
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
