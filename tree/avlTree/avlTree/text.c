#include "avl.h"
int main() {

	treeNode* T = NULL;
	int nums[5] = { 8,7,9,5,6 };
	for (int i = 0; i < 5; i++) {
		avlInsert(&T, nums[i]);
	}
	preOrder(T);
	printf("\n");
}