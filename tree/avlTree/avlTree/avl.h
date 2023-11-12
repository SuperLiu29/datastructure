	#include <stdio.h>
	#include <stdlib.h>

	typedef struct treeNode {
		int data;
		struct treeNode* lchild;
		struct treeNode* rchild;
		int height;
	}treeNode;
	int getHeight(treeNode* node);
	void llRotation(treeNode* node, treeNode** root);
	void rrRotation(treeNode* node, treeNode** root);
	void avlInsert(treeNode** T, int data);
	void preOrder(treeNode* T);