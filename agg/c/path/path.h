#include "stack.h"
#include<stdio.h>
struct PathsNode
{
    int data;
    struct PathsNode *next;
};

struct Paths
{
    int num;
    struct PathsNode *head;
    struct Paths *next;
};

struct Pathslist
{
    int num;
    struct Paths *start;
    struct Paths *tail;
};

struct Pathslist *init_paths();

struct Paths *cp_path(struct Stack *stack);

void add_path(struct Pathslist *paths, struct Stack *stack);

void DFS(int (*graph)[MAXNODE], int n, int start, int end, int *pathsNum, struct Pathslist *list);
