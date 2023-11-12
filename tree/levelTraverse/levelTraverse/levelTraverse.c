#include "levelTraverse.h"

void createTree(treeNode** T, char* data, int* index)
{
	char ch;
	ch = data[*index];
	*index += 1;
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (treeNode*)malloc(sizeof(treeNode));
		(*T)->data = ch;
		//�ݹ�
		createTree(&((*T)->lChild), data, index);
		createTree(&((*T)->rChild), data, index);
	}
}
void preOrder(treeNode* T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		//�ݹ�
		preOrder(T->lChild);
		preOrder(T->rChild);
	}
}
queueNode* initQueue()
{
	queueNode* Q = (queueNode*)malloc(sizeof(queueNode));
	Q->data = NULL;//�ڱ�λ
	Q->next = Q;
	Q->prev = Q;
	return Q;
}
void enQueue(treeNode* data, queueNode* Q)
{
	if (Q == NULL)
	{
		return;
	}
	queueNode* Qnewnode = (queueNode*)malloc(sizeof(queueNode));
	Qnewnode->data = data;
	//�ҵ�β���
	queueNode* tail = Q->prev;
	//����
	tail->next = Qnewnode;
	Qnewnode->prev = tail;
	Qnewnode->next = Q;
	Q->prev = Qnewnode;
}
bool isQueueEmpty(queueNode* Q)
{
	return Q->next == Q;
}
queueNode* deQueue(queueNode* Q)
{
	if (isQueueEmpty(Q))
	{
		return;
	}
	else
	{
		queueNode* node = Q->next;//ȡ��������ɾ���Ľ��
		//
		Q->next = node->next;
		node->next->prev = Q;
		return node;
	}
}
void levelTraverse(queueNode* Q, treeNode* T)
{
	//��α���
	enQueue(T, Q);
	while (!isQueueEmpty(Q))
	{
		queueNode* node = deQueue(Q);
		printf("%c ", node->data->data);
		if (node->data->lChild != NULL)
		{
			enQueue(node->data->lChild, Q);
		}
		if (node->data->rChild != NULL)
		{
			enQueue(node->data->rChild, Q);
		}
	}
}