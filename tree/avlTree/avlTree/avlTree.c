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
	//调整高度
	node->height = getMax(getHeight(node->lchild), getHeight(node->rchild)) + 1;
	temp->height = getMax(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;

	*root = temp;
}
void rrRotation(treeNode* node, treeNode** root) {
	treeNode* temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	//调整高度
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
		//插在左边
		avlInsert(&(*T)->lchild, data);
		//获得左右子树的高度
		int lheight = getHeight((*T)->lchild);
		int rheight = getHeight((*T)->rchild);
		//判断高度差
		if (lheight - rheight==2) {
			//此时需要调整
			//
			//在进行判断为LL还是LR
			if (data<(*T)->lchild->data) {
				//此时为LL调整
				llRotation(*T,T);
			}
			else {
				//此时为LR调整
				rrRotation((*T)->lchild, &(*T)->lchild);
				llRotation(*T, T);
			}
		}
	}
	else if (data > (*T)->data) {
		//插在右边
		avlInsert(&(*T)->rchild, data);
		//获得左右子树的高度
		int lheight = getHeight((*T)->lchild);
		int rheight = getHeight((*T)->rchild);
		if (rheight - lheight == 2) {
			//此时需要调整
			//
			//在进行判断为LL还是LR
			if (data > (*T)->rchild->data) {
				//此时为RR调整
				rrRotation(*T, T);
			}
			else {
				//此时为RL调整
				llRotation((*T)->rchild, &(*T)->rchild);
				rrRotation(*T, T);
			}
		}
	}
	else {
		return;
	}
	(*T)->height = getMax(getHeight((*T)->lchild), getHeight((*T)->rchild)) + 1;//调整高度

}
void preOrder(treeNode*T) {
	if (T) {
		printf("%d ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}


