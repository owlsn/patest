#include <stdio.h>
#include <string.h>
#include "stack.h"
#define MAXNODE 100

int main()
{
    //输入前序和中序
    char pre[MAXNODE], in[MAXNODE];
    scanf("%s", pre);
    scanf("%s", in);
    int length = strlen(pre);
    //根据两个序列构建一颗树，并返回根节点
    BinTreeNode *root = create_tree(pre, in, length);
    BinTreeNode *temp;
    //p节点存储上一次访问的节点，因为当
    BinTreeNode *p = NULL;
    //初始化栈结构
    struct Stack *stack = init_stack();
    push(stack, root);
    while (stack->length)
    {
        temp = top(stack);
        //只有当没有左右子树或者上一次访问的是左右子树，即子树已经访问完了，然后访问根节点
        if ((temp->left == NULL && temp->right == NULL) || (p != NULL && (temp->right == p || p == temp->left)))
        {
            printf("%c", temp->data);
            if(stack->length != 1){
                printf("->");
            }
            p = pop(stack);
        }
        else{
            if(temp->right != NULL){
                push(stack, temp->right);
            }
            if(temp->left != NULL){
                push(stack, temp->left);
            }
        }
    }
    return 0;
}