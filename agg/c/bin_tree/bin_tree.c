#include "bin_tree.h"

BinTreeNode *create_tree(char pre[], char in[], int length){
    //没有节点
    if(length <= 0){
        return NULL;
    }
    BinTreeNode *root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    root->data = pre[0];
    root->left = NULL;
    root->right = NULL;
    int position;
    for (int i = 0; i < length; i++)
    {
        if(in[i] == root->data){
            position = i;
            break;
        }
    }
    root->left = create_tree(pre + 1, in, position);
    root->right = create_tree(pre + position + 1, in + position + 1, length - position - 1);
    return root;
}