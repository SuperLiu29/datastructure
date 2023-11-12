#include <stdio.h>   
#include <malloc.h>  
#include <stdbool.h>
#include <assert.h>
#define MaxSize 100  

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];		//���ջ�е�����Ԫ��
	int top;					//ջ��ָ�룬�����ջ��Ԫ����data�����е��±�
}stack;
stack* initStack()
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->top = -1;
	return s;
}
void pushStack(stack*s,ElemType x)//��ջ
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = x;
}
ElemType popStack(stack* s, ElemType x)//��ջ
{
	assert(!isStackEmpty(s));
	x = s->data[s->top];
	s->top--;
	return x;
}
bool isStackEmpty(stack* s)
{
	return (s->top == -1);
}