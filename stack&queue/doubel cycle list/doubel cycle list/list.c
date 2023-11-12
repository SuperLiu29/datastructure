#include "list.h"
node* listInit()
{
	node* phead = (node*)malloc(sizeof(node));
	phead->data = 0;//��㸳ֵ��Ӱ��
	//��ǰ��ָ���Լ�
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void pushListBack(node* phead,LTDataType x)//β��
{
	assert(phead);
	node* pnewnode = (node*)malloc(sizeof(node));
	pnewnode->data = x;
	//��ʱ��Ҫ�ҵ�β���-��Ϊͷ������һ�����
	node* tail = phead->prev;
	//��ʱ����β��
	tail->next = pnewnode;
	pnewnode->next = phead;
	pnewnode->prev = tail;
	phead->prev = pnewnode;
	//����

}
void popListBack(node* phead)//βɾ
{
	assert(phead);
	assert(phead->next != phead);//������ǿ�.�������Ϊ��(��ֻ����һ���ڱ����),��ʱ����ɾ������ͷŵ��ڱ����
	//�����ҵ�β���
	node* tail = phead->prev;
	//��ͷ������һ��prevָ��β����prev
	phead->prev = tail->prev;
	//�����µ�β���ָ��ͷ���
	tail->prev->next = phead;
	//�ͷžɵ�β���
	free(tail);
}
void listPrint(node* phead)
{
	node* pnode = phead->next;//��Ϊͷ���Ϊ�ڱ����,���ŵ�����������
	while (pnode != phead)
	{
		printf("%d ", pnode->data);
		//ָ�����
		pnode = pnode->next;

	}
}