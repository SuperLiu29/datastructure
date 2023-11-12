#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
	int ltag;
	int rtag;
	struct TreeNode* parent;//��¼����
}treeNode;
void createTree(treeNode** T,char* data,int* index,treeNode*parent)//������
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
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		(*T)->parent = parent;
		createTree(&(*T)->lchild, data, index,*T);
		createTree(&(*T)->rchild, data, index,*T);
	}
}
void postThreadTree(treeNode*T,treeNode**pre)
{
	if (T)
	{
		postThreadTree(T->lchild, pre);
		postThreadTree(T->rchild, pre);
		//
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = *pre;
		}
		if (*pre!= NULL&&(*pre)->rchild == NULL)
		{
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
		}
		*pre = T;
		
	}
}
treeNode*getFirst(treeNode*T)//����������ж�����������
{
	while (T->ltag == 0)
	{
		T = T->lchild;
	}
	if (T->rtag==0)
	{
		return getFirst(T->rchild); 
	}
	return T;
}
treeNode* getNext(treeNode* node)
{
	if (node->rtag == 1)
	{
		return node->rchild;
	}
	else
	{
		//�ж����
		if (node->parent == NULL)
		{
			//��ʱΪ���ڵ�
			return NULL;
		}
		else if(node->parent->rchild==node)
		{
			//��ʱΪ�Һ���
			return node->parent;//���ظ�
		}
		else
		{
			//��ʱΪ����
			if (node->parent->rtag==0)
			{
				//˵���������Һ���
				return getFirst(node->parent->rchild);
			}
			else
			{
				return node->parent;
			}
		}
	}

}
int main()
{
	treeNode * T;
    int index = 0;
    treeNode* pre = NULL;
    char str[] = "ABD##E##CF##G##";
	treeNode* parent = NULL;
    createTree(&T, str, &index,parent);
	postThreadTree(T, &pre);
	for (treeNode* node = getFirst(T); node != NULL; node = getNext(node))
	{
		printf("%c ", node->data);
	}

	return 0;
}