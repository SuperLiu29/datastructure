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

node* listInit();//��ʼ��,�������ڱ����
void pushListBack(node* phead, LTDataType x);//β��
void popListBack(node* phead);//βɾ
void listPrint(node* phead);//��ӡ

