#include <stdio.h>   
#include <malloc.h>  
#include <stdbool.h>
#include <assert.h>
#define MaxSize 100  

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];		//存放栈中的数据元素
	int top;					//栈顶指针，即存放栈顶元素在data数组中的下标
}stack;
stack* initStack()
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->top = -1;
	return s;
}
void pushStack(stack*s,ElemType x)//进栈
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = x;
}
ElemType popStack(stack* s, ElemType x)//出栈
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