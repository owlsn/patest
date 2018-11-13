#include <stdlib.h>
#define MAXNODE 16
struct StackNode
{
    int data;
    struct StackNode *next;
};

struct Stack
{
    int length;
    struct StackNode *top;
    struct StackNode *bottom;
};

struct Stack *init_stack();

void push(struct Stack *s, int data);

int pop(struct Stack *s);

int stack_len(struct Stack *s);

int top(struct Stack *s);
