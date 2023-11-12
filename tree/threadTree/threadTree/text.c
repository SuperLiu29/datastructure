#include "threadTree.h"
/**
 * main function
 * @param argc the num of args
 * @param argv the command args
 * @return int
 */
int main() {
    TreeNode* T;
    TreeNode* pre = NULL;
    int index = 0;
    createTree(&T, "ABD##E##CF##G##", &index);
    inThreadTree(T, &pre);
    pre->rtag = 1;
    pre->rchild = NULL;
    for (TreeNode* node = getFirst(T); node != NULL; node = getNext(node)) {
        printf("%c ", node->data);
    }
    printf("\n");
    return 0;
}