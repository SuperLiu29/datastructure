#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef int dataType;
typedef struct stack
{
	dataType* a;
	int top;
	int capacity;
}st;

void initStack(st* pst);//初始化栈
void stackPush(st* pst, dataType x);//插入元素
void stackDestroy(st* pst);//摧毁栈
bool isStackEmpty(st* pst);//判断栈区是否为空
void stackPop(st* pst);//删除栈顶元素
int getStackSize(st* pst);//获取栈区元素个数
dataType stackTop(st* pst);//获取栈顶元素
void stackPrint(st* pst);
