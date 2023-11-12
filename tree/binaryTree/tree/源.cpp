#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode
{
	char data;
	struct treeNode* lchild;
	struct treeNode* rchild;
}treeNode;
void createTree(treeNode** T, char* data, int* index) {
	char ch = data[*index];
	*index += 1;
	if (ch == '#') {
		*T = NULL;
	}
	else {
		*T = (treeNode*)malloc(sizeof(treeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild, data, index);
		createTree(&(*T)->rchild, data, index);
	}
}
void preOrder(treeNode* T) {
	//先序遍历
	//先办事
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}
void inOrder(treeNode* T) {
	//中序遍历

	if (T == NULL) {
		return;
	}
	inOrder(T->lchild);
	printf("%c ", T->data);

	inOrder(T->rchild);
}
void postOrder(treeNode* T) {
	//后序遍历

	if (T == NULL) {
		return;
	}
	inOrder(T->lchild);

	inOrder(T->rchild);
	printf("%c ", T->data);
}
int main() {
	treeNode* T;
	int index = 0;
	createTree(&T, (char*)"ABD##E##CF##G##", &index);
	preOrder(T);
	printf("\n");
	inOrder(T);
	printf("\n");
	postOrder(T);
	printf("\n");
	return 0;
}