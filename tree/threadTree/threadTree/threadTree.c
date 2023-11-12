
#include "threadTree.h"


/**
 * use the char sequence to create a binary tree use pre order
 * @param T the second level of tree root node
 * @param data char sequence
 * @param index the index of char sequence
 */
void createTree(TreeNode** T, char* data, int* index) {
    char ch;
    ch = data[*index];
    *index += 1;
    if (ch == '#') {
        // 此时为空节点
        *T = NULL;
    }
    else {
        // 此时不为空
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->ltag = 0;
        (*T)->rtag = 0;
        // 创建左子树，逻辑一致，进行递归
        createTree(&((*T)->lchild), data, index);
        // 创建右子树，逻辑一致，进行递归
        createTree(&((*T)->rchild), data, index);
    }
}

/**
 * create in thread for a binary tree
 * @param T the pointer of tree root node
 * @param pre the second level pointer of the pre node for current node
 */
void inThreadTree(TreeNode* T, TreeNode** pre) {
    if (T) {
        inThreadTree(T->lchild, pre);
        // do something
        if (T->lchild == NULL) {
            T->ltag = 1;
            T->lchild = *pre;
        }
        if (*pre != NULL && (*pre)->rchild == NULL) {
            (*pre)->rtag = 1;
            (*pre)->rchild = T;
        }
        *pre = T;
        inThreadTree(T->rchild, pre);
    }
}

/**
 * find the traverse first node in tree
 * @param T the pointer of tree root node
 * @return the pointer of first node
 */
TreeNode* getFirst(TreeNode* T) {
    while (T->ltag == 0)
        T = T->lchild;
    return T;
}

/**
 * find a next tree node for current node
 * @param node the pointer of current node
 * @return the pointer of next node
 */
TreeNode* getNext(TreeNode* node) {
    if (node->rtag == 1)
        return node->rchild;
    else
        return getFirst(node->rchild);
}

