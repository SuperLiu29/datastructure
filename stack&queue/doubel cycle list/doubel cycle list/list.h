#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int LTDataType;
typedef struct listNode
{
	struct listNode* prev;
	struct listNode* next;
	LTDataType data;
}node;

node* listInit();//初始化,即生成哨兵结点
void pushListBack(node* phead, LTDataType x);//尾插
void popListBack(node* phead);//尾删
void listPrint(node* phead);//打印

