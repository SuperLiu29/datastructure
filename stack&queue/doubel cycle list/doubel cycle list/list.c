#include "list.h"
node* listInit()
{
	node* phead = (node*)malloc(sizeof(node));
	phead->data = 0;//随便赋值不影响
	//让前后都指向自己
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void pushListBack(node* phead,LTDataType x)//尾插
{
	assert(phead);
	node* pnewnode = (node*)malloc(sizeof(node));
	pnewnode->data = x;
	//此时需要找到尾结点-即为头结点的上一个结点
	node* tail = phead->prev;
	//此时进行尾插
	tail->next = pnewnode;
	pnewnode->next = phead;
	pnewnode->prev = tail;
	phead->prev = pnewnode;
	//结束

}
void popListBack(node* phead)//尾删
{
	assert(phead);
	assert(phead->next != phead);//即链表非空.如果链表为控(即只存在一个哨兵结点),此时进行删除则会释放掉哨兵结点
	//首先找到尾结点
	node* tail = phead->prev;
	//让头结点的上一个prev指向尾结点的prev
	phead->prev = tail->prev;
	//再让新的尾结点指向头结点
	tail->prev->next = phead;
	//释放旧的尾结点
	free(tail);
}
void listPrint(node* phead)
{
	node* pnode = phead->next;//因为头结点为哨兵结点,其存放的数据无意义
	while (pnode != phead)
	{
		printf("%d ", pnode->data);
		//指针后移
		pnode = pnode->next;

	}
}