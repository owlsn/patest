#include <stdlib.h>
typedef struct BinTreeNode{
    char data;
    struct BinTreeNode *left;
    struct BinTreeNode *right;
} BinTreeNode;

BinTreeNode *create_tree(char pre[], char in[], int length);