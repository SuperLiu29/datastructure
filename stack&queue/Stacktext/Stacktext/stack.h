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

void initStack(st* pst);//��ʼ��ջ
void stackPush(st* pst, dataType x);//����Ԫ��
void stackDestroy(st* pst);//�ݻ�ջ
bool isStackEmpty(st* pst);//�ж�ջ���Ƿ�Ϊ��
void stackPop(st* pst);//ɾ��ջ��Ԫ��
int getStackSize(st* pst);//��ȡջ��Ԫ�ظ���
dataType stackTop(st* pst);//��ȡջ��Ԫ��
void stackPrint(st* pst);
