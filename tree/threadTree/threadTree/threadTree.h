#include <stdio.h>
#include <stdlib.h>
/**
 * define struct of tree node
 */
    typedef struct TreeNode {
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int ltag;
    int rtag;
}TreeNode;
void createTree(TreeNode** T, char* data, int* index);
void inThreadTree(TreeNode* T, TreeNode** pre);
TreeNode* getFirst(TreeNode* T);
TreeNode* getNext(TreeNode* node);