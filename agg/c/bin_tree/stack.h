#include "bin_tree.h"
struct StackNode
{
    BinTreeNode * data;
    struct StackNode *next;
};

struct Stack
{
    int length;
    struct StackNode *top;
    struct StackNode *bottom;
};

struct Stack *init_stack();

void push(struct Stack *s, BinTreeNode * data);

BinTreeNode * pop(struct Stack *s);

int stack_len(struct Stack *s);

BinTreeNode * top(struct Stack *s);
