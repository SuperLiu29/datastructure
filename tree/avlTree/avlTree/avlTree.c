#include "avl.h"
int getHeight(treeNode* node){
	return node ? node->height : 0;
}
int getMax(int a,int b) {
	return a > b ? a : b;
}
void llRotation(treeNode*node,treeNode**root) {

	treeNode* temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	//�����߶�
	node->height = getMax(getHeight(node->lchild), getHeight(node->rchild)) + 1;
	temp->height = getMax(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;

	*root = temp;
}
void rrRotation(treeNode* node, treeNode** root) {
	treeNode* temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	//�����߶�
	node->height = getMax(getHeight(node->lchild), getHeight(node->rchild)) + 1;
	temp->height = getMax(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;

	*root = temp;
}



void avlInsert(treeNode** T,int data){
	if (*T == NULL) {
		*T = (treeNode*)malloc(sizeof(treeNode));
		(*T)->data = data;
		(*T)->height = 0;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}
	else if(data<(*T)->data){
		//�������
		avlInsert(&(*T)->lchild, data);
		//������������ĸ߶�
		int lheight = getHeight((*T)->lchild);
		int rheight = getHeight((*T)->rchild);
		//�жϸ߶Ȳ�
		if (lheight - rheight==2) {
			//��ʱ��Ҫ����
			//
			//�ڽ����ж�ΪLL����LR
			if (data<(*T)->lchild->data) {
				//��ʱΪLL����
				llRotation(*T,T);
			}
			else {
				//��ʱΪLR����
				rrRotation((*T)->lchild, &(*T)->lchild);
				llRotation(*T, T);
			}
		}
	}
	else if (data > (*T)->data) {
		//�����ұ�
		avlInsert(&(*T)->rchild, data);
		//������������ĸ߶�
		int lheight = getHeight((*T)->lchild);
		int rheight = getHeight((*T)->rchild);
		if (rheight - lheight == 2) {
			//��ʱ��Ҫ����
			//
			//�ڽ����ж�ΪLL����LR
			if (data > (*T)->rchild->data) {
				//��ʱΪRR����
				rrRotation(*T, T);
			}
			else {
				//��ʱΪRL����
				llRotation((*T)->rchild, &(*T)->rchild);
				rrRotation(*T, T);
			}
		}
	}
	else {
		return;
	}
	(*T)->height = getMax(getHeight((*T)->lchild), getHeight((*T)->rchild)) + 1;//�����߶�

}
void preOrder(treeNode*T) {
	if (T) {
		printf("%d ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}


