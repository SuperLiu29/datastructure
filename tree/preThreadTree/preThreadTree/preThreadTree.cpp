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
        // ��ʱΪ�սڵ�
        *T = NULL;
    }
    else {
        // ��ʱ��Ϊ��
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->ltag = 0;
        (*T)->rtag = 0;
        // �������������߼�һ�£����еݹ�
        createTree(&((*T)->lchild), data, index);
        // �������������߼�һ�£����еݹ�
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
        return node->rchild;//���غ��
    }
    return node->lchild;//��������
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