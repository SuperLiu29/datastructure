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
void preThreadTree(TreeNode* T, TreeNode** pre) {
    if (T) {
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
        if (T->ltag==0)
        {
            preThreadTree(T->lchild, pre);
            preThreadTree(T->rchild, pre);

        }
    }
}
TreeNode* getNext(TreeNode* node)
{
    if (node->ltag == 1 || node->rtag == 1)
    {
        return node->rchild;//返回后继
    }
    return node->lchild;//返回左孩子
}
int main()
{
    TreeNode* T;
    TreeNode* pre = NULL;
    int index = 0;
    char str[16]="ABD##E##CF##G##";

    createTree(&T, str, &index);
    preThreadTree(T, &pre);
    pre->rtag = 1;
    pre->rchild = NULL;
    for (TreeNode* node = T; node != NULL; node = getNext(node))
    {
        printf("%c", node->data);
    }




}